//
// Created by zhangcl on 12/13/18.
//

#include "protocol.h"

#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

protocol::protocol() {

}

protocol::~protocol() {

}

em_check protocol::check(const unsigned char* pSrc, size_t len) {

    /*
     * {BYTE}:header, {BYTE,BYTE,BYTE,BYTE}:lengthofcontent, {BYTE*}:content, {BYTE}:checksum, {BYTE}:tail
     * */
    /*
     * header---
     *
     * 1:request up xml_for_terminal_checked
     * 2:response 1
     *
     * 3:request down xml_for_terminal_strategy
     * 4:response 3
     *
     * 5:request down xml_for_terminal_blackwhiteform
     * 6:response 5
     * */

    /*
     * tail---
     * 0
     * */

    if (7 <= len) {
        if ((1 == pSrc[0] || 3 == pSrc[0] || 5 == pSrc[0]) && 0 == pSrc[len - 1]) {
            uint32_t u32_t_tmp = *((uint32_t *) &pSrc[1]);
            uint32_t len_content = ntohl(u32_t_tmp);
            if ((len - 7) == len_content) {
                if (0 == len_content) {
                    if (0 != pSrc[len - 2]) {
                        return FCHECKED;
                    }
                    else {
                        return RIGHT;
                    }
                }
                else {
                    unsigned char checksum = 0;
                    for (size_t i = 0; i < len_content; i++) {
                        checksum += pSrc[sizeof(unsigned char) + sizeof(uint32_t) + i];
                    }
                    if (checksum != pSrc[len - 2]) {
                        return FCHECKED;
                    }
                    else {
                        return RIGHT;
                    }
                }
            }
            else {
                return NOCOMPLETED;
            }
        }
        else {
            return FCHECKED;
        }
    }

    return NOCOMPLETED;
}

void protocol::gainID(const unsigned char* pSrc, size_t len, char ID[256]) {
    uint32_t u32_t_tmp = *((uint32_t *) &pSrc[1]);
    size_t len_content = ntohl(u32_t_tmp);

    const unsigned char *p1 = (unsigned char *)&pSrc[sizeof(unsigned char) + sizeof(uint32_t)];
    size_t l1 = 0;

    for (size_t i = 0; i < len_content; i++) {
        if (i < 256 && p1[i] == ';') {
            l1 = i;
            ID[l1] = 0;
            memcpy(ID, p1, l1);
            break;
        }
    }
}

const std::vector<unsigned char>& protocol::parse_failure_result(const unsigned char* pSrc, size_t len) {
    switch (pSrc[0]) {
        case 1:
            vec_result.push_back(2);
            break;
        case 3:
            vec_result.push_back(4);
            break;
        case 5:
            vec_result.push_back(6);
            break;
    }

    char ID[256] = {0};
    gainID(pSrc, len, ID);

    const char* err = "sorry";

    char IDErr[256] = {0};
    sprintf(IDErr,"%s;%s", ID, err);

    size_t len_content = strlen(IDErr) + 1;
    uint32_t u32_t_tmp = (uint32_t)len_content;
    uint32_t u32_t_n = htonl(u32_t_tmp);
    unsigned char* tmp = (unsigned char *)&u32_t_n;
    for(size_t i = 0; i < sizeof(uint32_t); i++) {
        vec_result.push_back(tmp[i]);
    }
    unsigned char checksum = 0;
    tmp = (unsigned char *)IDErr;
    for(size_t i = 0; i < len_content; i++) {
        checksum += tmp[i];
        vec_result.push_back(tmp[i]);
    }
    vec_result.push_back(checksum);
    vec_result.push_back(0);

    return vec_result;
}

const std::vector<unsigned char>& protocol::parse_command(const unsigned char* pSrc, size_t len) {
    char ID[256] = {0};
    gainID(pSrc, len, ID);

    // execute command
    uint32_t u32_t_tmp = *((uint32_t *) &pSrc[1]);
    size_t len_content = ntohl(u32_t_tmp);

    size_t errLen = 0;
    unsigned char* err =
            command(pSrc[0], (unsigned char *)&pSrc[sizeof(unsigned char) + sizeof(uint32_t)], len_content, &errLen);

    //response
    switch (pSrc[0]) {
        case 1:
            vec_result.push_back(2);
            break;
        case 3:
            vec_result.push_back(4);
            break;
        case 5:
            vec_result.push_back(6);
            break;
    }

    size_t IDErrLen = strlen(ID) + 1 + errLen;

    char* IDErr = new char[IDErrLen];
    sprintf(IDErr,"%s;", ID);

    memcpy(IDErr + strlen(IDErr), err, errLen);

    len_content = IDErrLen;
    u32_t_tmp = (uint32_t)len_content;
    uint32_t u32_t_n = htonl(u32_t_tmp);
    unsigned char* tmp = (unsigned char *)&u32_t_n;
    for(size_t i = 0; i < sizeof(uint32_t); i++) {
        vec_result.push_back(tmp[i]);
    }
    unsigned char checksum = 0;
    tmp = (unsigned char *)IDErr;
    for(size_t i = 0; i < len_content; i++) {
        checksum += tmp[i];
        vec_result.push_back(tmp[i]);
    }
    vec_result.push_back(checksum);
    vec_result.push_back(0);

    delete[] IDErr;

    delete[] err;

    return vec_result;
}

unsigned char* protocol::command(unsigned char header, unsigned char* pSrc, size_t len, size_t* pOutLen) {
    const unsigned char *p1 = pSrc, *p2 = pSrc;
    size_t l1 = 0, l2 = 0;

    for (size_t i = 0; i < len; i++) {
        if (pSrc[i] == ';') {
            pSrc[i] = 0;

            l1 = i;
            p2 = &pSrc[i + 1];
            l2 = len - i -1;
            break;
        }
    }

    if (0 < l1 && l2 < len) {
        if (1 == header) {
            const char* pID = (char *)p1;
            char path[256] = {0};
            sprintf(path, "./%s", pID);
            int ret = 0;
            if (0 != access(path, F_OK)) {
                ret = mkdir(path, S_IRWXU);
            }

            if (0 == ret) {
                char pathfile[256] = {0};
                sprintf(pathfile, "%s/ck_info.xml", path);
                int fd = open(pathfile, O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);

                if (-1 != fd) {
                    ssize_t wlen = write(fd, p2, l2);
                    if (-1 == wlen) {
                        printf("write file %s, errno:%d\n", pathfile, errno);
                    }
                    close(fd);
                }
            }

            char* err = new char[256];
            strcpy(err, "ok");
            *pOutLen = strlen(err) + 1;

            return (unsigned char *)err;
        }
        else if (3 == header) {
            const char* pID = (char *)p1;
            char path[256] = {0};
            sprintf(path, "./%s", pID);

            char pathfile[256] = {0};
            sprintf(pathfile, "%s/strategy_info.xml", path);

            int ret = access(pathfile, F_OK);
            if (0 != ret) {
                char* err = new char[256];
                strcpy(err, "no exist!");
                *pOutLen = strlen(err) + 1;
                return (unsigned char *)err;
            }
            else {
                struct stat statbuff = {0};

                if (0 <= stat(pathfile, &statbuff))
                {
                    off_t flen = statbuff.st_size;
                    char* err = new char[flen];

                    int fd = open(pathfile, O_RDONLY, S_IRWXU);
                    ssize_t rlen = read(fd, err, flen);
                    if (-1 == rlen) {
                        printf("read file %s, errno:%d\n", pathfile, errno);
                    }
                    close(fd);

                    *pOutLen = rlen;
                    return (unsigned char *)err;
                }
                else {
                    return NULL;
                }
            }
        }
        else if (5 == header) {
            const char* pID = (char *)p1;
            char path[256] = {0};
            sprintf(path, "./%s", pID);

            char pathfile[256] = {0};
            sprintf(pathfile, "%s/black_white_form_info.xml", path);

            int ret = access(pathfile, F_OK);
            if (0 != ret) {
                char* err = new char[256];
                strcpy(err, "no exist!");
                *pOutLen = strlen(err) + 1;
                return (unsigned char *)err;
            }
            else {
                struct stat statbuff = {0};

                if (0 <= stat(pathfile, &statbuff))
                {
                    off_t flen = statbuff.st_size;
                    char* err = new char[flen];

                    int fd = open(pathfile, O_RDONLY, S_IRWXU);
                    ssize_t rlen = read(fd, err, flen);
                    if (-1 == rlen) {
                        printf("read file %s, errno:%d\n", pathfile, errno);
                    }
                    close(fd);

                    *pOutLen = rlen;
                    return (unsigned char *)err;
                }
                else {
                    return NULL;
                }
            }
        }
    }

    return NULL;
}