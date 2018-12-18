//
// Created by zhangcl on 12/13/18.
//

#ifndef CZZ_SERV_USERDEAL_H
#define CZZ_SERV_USERDEAL_H

#include <vector>

class userdeal {
public:
    userdeal();
    virtual ~userdeal();
protected:
    std::vector<unsigned char> vec_in;
    std::vector<unsigned char> vec_out;
    size_t pos_out;
public:
    void recvfd(void* arg);
    void sendfd(void* arg);
protected:
    virtual void readfd(int fd, bool& ClientClosed, bool& ReadFinished);
    virtual void writefd(int fd, bool& ClientClosed, bool& WriteFinished);
};


#endif //CZZ_SERV_USERDEAL_H
