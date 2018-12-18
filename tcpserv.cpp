//
// Created by zhangcl on 12/12/18.
//

#include "tcpserv.h"


tcpserv::tcpserv(int port)
{
    epfd = 0;
    _port = port;
    listenfd = 0;
    tid = 0;

    thpool = thpool_init(16);
}

tcpserv::~tcpserv()
{
    if (tid) {
        void* ret = NULL;
        pthread_cancel(tid);
        pthread_join(tid, &ret);
    }

    thpool_destroy(thpool);

    if (epfd) {
        close(epfd);
    }
    if (listenfd) {
        close(listenfd);
    }

    for(std::map<int, void*>::iterator it = userdeals.begin(); it != userdeals.end(); it++) {
        userdeal* dl = (userdeal *)(*it).second;
        if (dl)
            delete dl;
    }
}

void tcpserv::setnonblocking(int sock) {
    int opts;
    opts = fcntl(sock, F_GETFL);
    if (opts < 0)
    {
        perror("fcntl(sock,GETFL)");
        exit(1);
    }
    opts = opts|O_NONBLOCK;
    if (fcntl(sock, F_SETFL, opts) < 0)
    {
        perror("fcntl(sock,SETFL,opts)");
        exit(1);
    }
}

void tcpserv::epoll_del(epoll_event ee) {
    int connfd = ee.data.fd;
    epoll_ctl(epfd, EPOLL_CTL_DEL, connfd, NULL);
    close(connfd);
}

void tcpserv::epoll_mod_in(epoll_event ee) {
    struct epoll_event ev = {0};
    int connfd = ee.data.fd;
    ev.data.fd = connfd;
    ev.events = EPOLLIN|EPOLLET|EPOLLONESHOT;
    epoll_ctl(epfd, EPOLL_CTL_MOD, connfd, &ev);
}

void tcpserv::epoll_mod_out(epoll_event ee) {
    struct epoll_event ev = {0};
    int connfd = ee.data.fd;
    ev.data.fd = connfd;
    ev.events = EPOLLOUT|EPOLLET|EPOLLONESHOT;
    epoll_ctl(epfd, EPOLL_CTL_MOD, connfd, &ev);
}

void tcpserv::epoll_ptr_del(epoll_event ee) {
    userdeal* dl = (userdeal *)userdeals[ee.data.fd];
    if (dl)
        delete dl;
    userdeals.erase(ee.data.fd);
}

void tcpserv::start() {
    struct epoll_event ev = {0}, events[1024] = {0};
    epfd = epoll_create(1024);
    struct sockaddr_in clientaddr = {0};
    struct sockaddr_in serveraddr = {0};
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    setnonblocking(listenfd);

    ev.data.fd = listenfd;
    ev.events = EPOLLIN|EPOLLET;

    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(_port);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd,(sockaddr*)&serveraddr, sizeof(serveraddr));
    listen(listenfd, 20);

    pthread_create(&tid, NULL, run, this);
}

void* tcpserv::run(void* pVoid) {

    if (!pVoid)
        return (void*)-1;
    tcpserv* pthis = (tcpserv*)pVoid;

    pthread_cleanup_push(cleanup, pVoid);

    while(true)
    {
        pthread_testcancel();
        pthis->doing();
        // just for code to need
        if (!pthis->epfd) {
            break;
        }
    }

    pthread_cleanup_pop(0);

    pthread_exit(0);
}

void tcpserv::cleanup(void *arg)
{
}

void tcpserv::doing() {
    struct epoll_event ev = {0}, events[1024] = {0};

    int nfds = epoll_wait(epfd, events, 1024, 500);

    struct sockaddr_in clientaddr = {0};
    socklen_t clilen = 0;
    int connfd;

    for (int i = 0; i < nfds; ++i) {
        bzero(&ev, sizeof(ev));

        if (events[i].data.fd == listenfd) {

            connfd = accept(listenfd, (sockaddr *) &clientaddr, &clilen);
            if (connfd > 0) {
                userdeal* ud = new userdeal();
                userdeals[connfd] = ud;

                setnonblocking(connfd);
                ev.data.fd = connfd;
                ev.events = EPOLLIN|EPOLLET|EPOLLONESHOT;
                epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
            }

            /*
            ev.data.fd = listenfd;
            ev.events = EPOLLIN|EPOLLET;
            epoll_ctl(epfd, EPOLL_CTL_MOD, listenfd, &ev);
            */
        }
        else if (events[i].events&EPOLLIN) {
            read(events[i]);
        }
        else if (events[i].events&EPOLLOUT) {
            write(events[i]);
        }
    }
}

void tcpserv::read(epoll_event ee) {
    void* pUserObject = userdeals[ee.data.fd];

    if (pUserObject) {
        deal* dl = new deal();
        dl->_userdeal = (userdeal *)pUserObject;
        dl->_tcpserv = this;
        dl->ee = ee;
        thpool_add_work(thpool, input, dl);
    }
}

void tcpserv::write(epoll_event ee) {
    void* pUserObject = userdeals[ee.data.fd];

    if (pUserObject) {
        deal* dl = new deal();
        dl->_userdeal = (userdeal *)pUserObject;
        dl->_tcpserv = this;
        dl->ee = ee;
        thpool_add_work(thpool, output, dl);
    }
}

void tcpserv::input(void* arg) {
    deal* dl = (deal *)arg;
    dl->_userdeal->recvfd(dl);
}

void tcpserv::output(void* arg) {
    deal* dl = (deal *)arg;
    dl->_userdeal->sendfd(dl);
}