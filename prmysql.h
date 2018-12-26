//
// Created by zhangcl on 12/25/18.
//

#ifndef CZZ_SERV_PRMYSQL_H
#define CZZ_SERV_PRMYSQL_H

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>


class prmysql {
    MYSQL *conn;
private:
    std::string my_db;
    std::string server;
    std::string user;
    std::string password;
private:
    void init();
public:
    prmysql(const char* serverIP, const char* userName, const char* passWord);
    virtual ~prmysql();
public:
    bool IsExistDB();
    bool createDB();
    bool createTB();
};


#endif //CZZ_SERV_PRMYSQL_H
