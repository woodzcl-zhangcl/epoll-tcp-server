//
// Created by zhangcl on 12/25/18.
//

#ifndef CZZ_SERV_PRMYSQL_H
#define CZZ_SERV_PRMYSQL_H

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>

#include "prxml.h"

extern std::string db_ip;
extern std::string db_username;
extern std::string db_password;

struct ST_STRATEGY
{
    std::string SgyID;
    std::string name;
    std::string des;
    std::string set;
    ST_STRATEGY() {
        SgyID = "";
        name = "";
        des = "";
        set = "";
    }
};

struct ST_BWFORM
{
    std::string procname;
    std::string des;
    ST_BWFORM() {
        procname = "";
        des = "";
    }
};

class prmysql {
    std::string ID;
    MYSQL *conn;
    bool bConnected;
private:
    std::string my_db;
    std::string server;
    std::string user;
    std::string password;
private:
    void init();
public:
    prmysql(const char* serverIP, const char* userName, const char* passWord, bool bConnect = false);
    virtual ~prmysql();
public:
    void SetID(const char* pID);
public:
    bool IsExistDB();
    bool createDB();
    bool createTB();
public:
    void CheckFileToDB(std::map<std::string, std::string> &hwinfo,
            std::vector<ST_SHIELD> sdinfo, std::vector<ST_SERVICE> svcinfo,
                       std::vector<ST_SOFTWARE> swinfo);
    std::vector<ST_STRATEGY> GetStrategyFromDB();
    std::vector<ST_BWFORM> GetBWFormFromDB();
};


#endif //CZZ_SERV_PRMYSQL_H
