//
// Created by zhangcl on 12/13/18.
//

#ifndef CZZ_SERV_PROTOCOL_H
#define CZZ_SERV_PROTOCOL_H

#include <stddef.h>
#include <vector>

enum em_check {
    RIGHT = 0,
    FCHECKED = 1,
    NOCOMPLETED = 2
};

class protocol {
public:
    protocol();
    virtual ~protocol();
protected:
    std::vector<unsigned char> vec_result;
public:
    virtual em_check check(const unsigned char* pSrc, size_t len);
protected:
    void gainID(const unsigned char* pSrc, size_t len, char ID[256]);
public:
    virtual const std::vector<unsigned char>& parse_failure_result(const unsigned char* pSrc, size_t len);
    virtual const std::vector<unsigned char>& parse_command(const unsigned char* pSrc, size_t len);
protected:
    virtual unsigned char* command(unsigned char header, unsigned char* pSrc, size_t len, size_t* pOutLen);
};


#endif //CZZ_SERV_PROTOCOL_H
