//
// Created by zhangcl on 12/13/18.
//

#include "userdeal.h"
#include "tcpserv.h"
#include "protocol.h"


userdeal::userdeal() {
    pos_out = 0;
}

userdeal::~userdeal() {

}

void userdeal::recvfd(void* arg) {
    deal* dl = (deal *)arg;

    epoll_event ee = dl->ee;
    bool bCliClose = false;
    bool bReadFinished = false;

    readfd(ee.data.fd, bCliClose, bReadFinished);

    if (bCliClose) {
        dl->_tcpserv->epoll_del(ee);
        dl->_tcpserv->epoll_ptr_del(ee);
    }
    else {
        if (!bReadFinished) {
            dl->_tcpserv->epoll_mod_in(ee);
        }
        else {
            dl->_tcpserv->epoll_mod_out(ee);
        }
    }

    delete dl;
}

void userdeal::sendfd(void* arg) {
    deal* dl = (deal *)arg;

    epoll_event ee = dl->ee;
    bool bCliClose = false;
    bool bWriteFinished = false;

    writefd(ee.data.fd, bCliClose, bWriteFinished);

    if (bCliClose) {
        dl->_tcpserv->epoll_del(ee);
        dl->_tcpserv->epoll_ptr_del(ee);
    }
    else {
        if (!bWriteFinished) {
            dl->_tcpserv->epoll_mod_out(ee);
        }
        else {
            dl->_tcpserv->epoll_mod_in(ee);
        }
    }

    delete dl;
}

void userdeal::readfd(int fd, bool& ClientClosed, bool& ReadFinished) {
    unsigned char buf[1024];
    ssize_t ret = 0;

    while(true) {
        ret = recv(fd, buf, 1024, 0);
        if (0 == ret) {
            ClientClosed = true;
            break;
        }
        else if (0 > ret) {
            if ((errno == EAGAIN) || (errno == EWOULDBLOCK ||errno == EINTR)) {
                break;
            }
            else {
                ClientClosed = true;
                break;
            }
        }
        else {
            for(ssize_t i = 0; i < ret; i++) {
                vec_in.push_back(buf[i]);
            }
        }
    }

    protocol pl;
    em_check ec = pl.check(vec_in.size() > 0 ? &vec_in[0] : NULL, vec_in.size());
    if (RIGHT == ec || FCHECKED == ec) {
        ReadFinished = true;
        std::vector<unsigned char> tmp_out;
        if (FCHECKED == ec) {
            tmp_out = pl.parse_failure_result(&vec_in[0], vec_in.size());
        }
        else {
            tmp_out = pl.parse_command(&vec_in[0], vec_in.size());
        }
        vec_out.resize(tmp_out.size());
        pos_out = 0;
        if (0 < tmp_out.size()) {
            memcpy(&vec_out[0], &tmp_out[0], tmp_out.size());
        }
    }
}

void userdeal::writefd(int fd, bool& ClientClosed, bool& WriteFinished) {
    unsigned char buf[1024];
    size_t sendlen = 0;
    unsigned char* pSrc = 0 < vec_out.size() ? &vec_out[pos_out] : NULL;
    size_t SrcLen = vec_out.size() - pos_out;
    size_t wlen = 0;
    ssize_t ret;

    while(true) {
        if (wlen >= SrcLen) {
            pos_out = 0;
            vec_in.clear();
            vec_out.clear();
            WriteFinished = true;
            break;
        }
        else {
            sendlen = SrcLen - wlen;
            if (sendlen <= 1024) {
                memcpy(buf, pSrc + wlen, sendlen);
            }
            else {
                sendlen = 1024;
                memcpy(buf, pSrc + wlen, sendlen);
            }

            ret = send(fd, buf, sendlen, 0);
            if (0 == ret) {
                if (0 < sendlen) {
                    ClientClosed = true;
                    break;
                }
            }
            else if (0 > ret) {
                if ((errno == EAGAIN) || (errno == EWOULDBLOCK ||errno == EINTR)) {
                    pos_out += wlen;
                    break;
                }
                else {
                    ClientClosed = true;
                    break;
                }
            }
            else {
                wlen += ret;
            }
        }
    }
}