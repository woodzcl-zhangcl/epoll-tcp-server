#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "prxml.h"
#include "tcpserv.h"

bool bRun = true;

void Stop(int signo)
{
    printf("\nstop!!!\n");
    bRun = false;
}

int main() {
    signal(SIGINT, Stop);

    struct sigaction sa = {0};
    sa.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &sa, 0);

//    prxml xml;
//    xml.Parse("ck_info.xml");

    tcpserv serv(8096);
    serv.start();

    while(bRun) {
        char c = getchar();
        if (c == 'e') {
            bRun = false;
        }
    }


    return 0;
}