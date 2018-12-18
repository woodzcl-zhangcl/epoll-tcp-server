//
// Created by zhangcl on 12/12/18.
//

#ifndef CZZ_SERV_TCPSERV_H
#define CZZ_SERV_TCPSERV_H

#include "thpool.h"
#include "userdeal.h"

#include <iostream>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <map>

#define MYPORT  89807
#define QUEUE   20

class tcpserv {
public:
    tcpserv(int port);
    virtual ~tcpserv();

private:
    int epfd;
    int _port;
    int listenfd;
    pthread_t tid;

    threadpool thpool;
private:
    void setnonblocking(int sock);
public:
    std::map<int, void*> userdeals;
public:
    void epoll_del(epoll_event ee);
    void epoll_mod_in(epoll_event ee);
    void epoll_mod_out(epoll_event ee);
    virtual void epoll_ptr_del(epoll_event ee);
public:
    void start();
private:
    static void* run(void* pVoid);
    static void cleanup(void *arg);
    void doing();
protected:
    virtual void read(epoll_event ee);
    virtual void write(epoll_event ee);
    static void input(void* arg);
    static void output(void* arg);
};

typedef struct _deal {
    userdeal* _userdeal;
    tcpserv* _tcpserv;
    epoll_event ee;
}deal, *pdeal;

#endif //CZZ_SERV_TCPSERV_H
