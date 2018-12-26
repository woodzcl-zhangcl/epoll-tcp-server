#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "prxml.h"
#include "tcpserv.h"

#include "prmysql.h"

bool bRun = true;

void Stop(int signo)
{
    printf("\nstop!!!\n");
    bRun = false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: czz_serv port\n");
        return 0;
    }

    char* stopstring;
    int Port = (int)strtol(argv[1], &stopstring, 10);

    signal(SIGINT, Stop);

    struct sigaction sa = {0};
    sa.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &sa, 0);

//    prxml xml;
//    xml.Parse("ck_info.xml");

    prmysql sql("127.0.0.1", "test", "test");
    if (!sql.IsExistDB())
    {
        if (sql.createDB())
        {
            sql.createTB();
        }
    }

    tcpserv serv(Port);
    serv.start();

    while(bRun) {
        char c = getchar();
        if (c == 'e') {
            bRun = false;
        }
    }


    return 0;
}