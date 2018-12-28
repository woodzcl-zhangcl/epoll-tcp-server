#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "prxml.h"
#include "tcpserv.h"

#include "prmysql.h"
#include <string>

bool bRun = true;

void Stop(int signo)
{
    printf("\nstop!!!\n");
    bRun = false;
}

std::string db_ip;
std::string db_username;
std::string db_password;

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: czz_serv port DbIP DbUserName DbPassword\n");
        return 0;
    }

    char* stopstring;
    int Port = (int)strtol(argv[1], &stopstring, 10);

    db_ip = argv[2];
    db_username = argv[3];
    db_password = argv[4];

    signal(SIGINT, Stop);

    struct sigaction sa = {0};
    sa.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &sa, 0);

    prmysql* sql = new prmysql(db_ip.c_str(), db_password.c_str(), db_password.c_str());
    if (!sql->IsExistDB())
    {
        if (sql->createDB())
        {
            sql->createTB();
        }
    }
    delete sql;

    tcpserv serv(Port);
    serv.start();

    while(bRun) {
        char c = getchar();
        if (c == 'e') {
            bRun = false;
        }
    }

    mysql_library_end();

    return 0;
}