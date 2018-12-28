//
// Created by zhangcl on 12/25/18.
//

#include "prmysql.h"
#include <cstring>

void prmysql::init()
{
    if (conn) {
        mysql_close(conn);
        conn = NULL;
    }
    conn = mysql_init(NULL);
}

prmysql::prmysql(const char* serverIP, const char* userName, const char* passWord, bool bConnect)
{
    conn = mysql_init(NULL);

    my_db = "czz_db";
    bConnected = false;

    server = serverIP;
    user = userName;
    password = passWord;

    if (bConnect)
    {
        MYSQL* sql =
                mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), my_db.c_str(), 0, NULL, 0);
        if (sql)
        {
            bConnected = true;
        }
    }

//    MYSQL *conn;
//    MYSQL_RES *res;
//    MYSQL_ROW row;
//
//    conn = mysql_init(NULL);
//
//    if (!mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), "mysql", 0, NULL, 0))
//    {
//        fprintf(stderr, "%s\n", mysql_error(conn));
//        exit(1);
//    }
//
//    if (mysql_query(conn, "show tables"))
//    {
//        fprintf(stderr, "%s\n", mysql_error(conn));
//        exit(1);
//    }
//
//    res = mysql_use_result(conn);
//
//    printf("MySQL Tables in mysql database:\n");
//
//    while (NULL != (row = mysql_fetch_row(res)))
//    {
//        printf("%s \n", row[0]);
//    }
//
//    mysql_free_result(res);
//    mysql_close(conn);
//    mysql_library_end();
//
//    printf("finish! \n");

//    MYSQL *conn;
//    MYSQL_RES *res;
//    MYSQL_ROW row;
//
//    conn = mysql_init(NULL);
//
//    if (!mysql_real_connect(conn, "127.0.0.1", "test", "test", "czz_db", 0, NULL, 0))
//    {
//        fprintf(stderr, "%s\n", mysql_error(conn));
//        exit(1);
//    }
//
//    int r = mysql_query(conn, "select status from checkinfo_shield");
//    res = mysql_use_result(conn);
//    while(NULL != (row = mysql_fetch_row(res)))
//    {
//        const char* cp = row[0];
//        printf("Ok.\n");
//    }
//    mysql_free_result(res);//释放记录集
//
//    mysql_close(conn);
//    mysql_library_end();
}

prmysql::~prmysql()
{
    if (conn)
        mysql_close(conn);
}

void prmysql::SetID(const char* pID)
{
    ID = pID;
}

bool prmysql::IsExistDB()
{
    bool ret = false;

    if (mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), my_db.c_str(), 0, NULL, 0))
    {
        MYSQL_RES* result1 = mysql_list_tables(conn, "checkinfo_hardware");
        MYSQL_RES* result2 = mysql_list_tables(conn, "checkinfo_shield");
        MYSQL_RES* result3 = mysql_list_tables(conn, "checkinfo_service");
        MYSQL_RES* result4 = mysql_list_tables(conn, "checkinfo_software");
        MYSQL_RES* result5 = mysql_list_tables(conn, "strategy");
        MYSQL_RES* result6 = mysql_list_tables(conn, "bwform");
        if (result1 && result2 && result3 && result4 && result5 && result6)
        {

            MYSQL_ROW row1 = mysql_fetch_row(result1);
            MYSQL_ROW row2 = mysql_fetch_row(result2);
            MYSQL_ROW row3 = mysql_fetch_row(result3);
            MYSQL_ROW row4 = mysql_fetch_row(result4);
            MYSQL_ROW row5 = mysql_fetch_row(result5);
            MYSQL_ROW row6 = mysql_fetch_row(result6);
            if (NULL != row1 && NULL != row2 && NULL != row3
            && NULL != row4 && NULL != row5 && NULL != row6)
            {
                ret = true;
            }
        }

        mysql_free_result(result1);
        mysql_free_result(result2);
        mysql_free_result(result3);
        mysql_free_result(result4);
        mysql_free_result(result5);
        mysql_free_result(result6);
    }


    return ret;
}

bool prmysql::createDB()
{
    bool ret = false;

    if (mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), my_db.c_str(), 0, NULL, 0))
    {
        ret = true;
    }
    else{
        if (mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), "mysql", 0, NULL, 0)) {
            std::string queryStr = "create database ";
            queryStr += my_db.c_str();
            if (0 != mysql_query(conn, queryStr.c_str())) {
                fprintf(stderr, "%s\n", mysql_error(conn));
            } else {
                queryStr = "use ";
                queryStr += my_db;
                if (0 != mysql_query(conn, queryStr.c_str()))
                {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                }
                else
                {
                    return true;
                }
            }
        }
    }

    return ret;
}

bool prmysql::createTB()
{
    bool ret = false;

    if (conn)
    {
        MYSQL_RES* result1 = mysql_list_tables(conn, "checkinfo_hardware");
        MYSQL_RES* result2 = mysql_list_tables(conn, "checkinfo_shield");
        MYSQL_RES* result3 = mysql_list_tables(conn, "checkinfo_service");
        MYSQL_RES* result4 = mysql_list_tables(conn, "checkinfo_software");
        MYSQL_RES* result5 = mysql_list_tables(conn, "strategy");
        MYSQL_RES* result6 = mysql_list_tables(conn, "bwform");
        if (result1 && result2 && result3 && result4 && result5 && result6)
        {
            bool bSuccess = false;
            while(true) {
                MYSQL_ROW row1 = mysql_fetch_row(result1);
                MYSQL_ROW row2 = mysql_fetch_row(result2);
                MYSQL_ROW row3 = mysql_fetch_row(result3);
                MYSQL_ROW row4 = mysql_fetch_row(result4);
                MYSQL_ROW row5 = mysql_fetch_row(result5);
                MYSQL_ROW row6 = mysql_fetch_row(result6);
                if (NULL == row1) {
                    const char* sql = "create table checkinfo_hardware("
                                      "id INT NOT NULL AUTO_INCREMENT,"
                                      "Identity VARCHAR(100) NOT NULL,"
                                      "MachineName VARCHAR(100),"
                                      "MotherboardID VARCHAR(100),"
                                      "CPUType VARCHAR(100),"
                                      "CPUNumber VARCHAR(100),"
                                      "MemoryCapacity VARCHAR(100),"
                                      "MemoryNumber VARCHAR(100),"
                                      "DiskType VARCHAR(100),"
                                      "DiskCapacity VARCHAR(100),"
                                      "DiskNumber VARCHAR(100),"
                                      "DiskPartition VARCHAR(100),"
                                      "LocalIP VARCHAR(100),"
                                      "VideoCardType VARCHAR(100),"
                                      "VideoCardNumber VARCHAR(100),"
                                      "CreateTime DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                                      "PRIMARY KEY (id)"
                                      ")";
                    if (0 != mysql_query(conn, sql)){
                        break;
                    }
                }
                if (NULL == row2){
                    const char* sql = "create table checkinfo_shield("
                                      "id INT NOT NULL AUTO_INCREMENT,"
                                      "Identity VARCHAR(100) NOT NULL,"
                                      "displayName VARCHAR(100),"
                                      "pathToSignedProductExe VARCHAR(100),"
                                      "status VARCHAR(100),"
                                      "CreateTime DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                                      "PRIMARY KEY (id)"
                                      ")";
                    if (0 != mysql_query(conn, sql)){
                        break;
                    }
                }
                if (NULL == row3){
                    const char* sql = "create table checkinfo_service("
                                      "id INT NOT NULL AUTO_INCREMENT,"
                                      "Identity VARCHAR(100) NOT NULL,"
                                      "DisplayName VARCHAR(100),"
                                      "ServiceName VARCHAR(100),"
                                      "ServiceType VARCHAR(100),"
                                      "status VARCHAR(100),"
                                      "CreateTime DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                                      "PRIMARY KEY (id)"
                                      ")";
                    if (0 != mysql_query(conn, sql)){
                        break;
                    }
                }
                if (NULL == row4) {
                    const char* sql = "create table checkinfo_software("
                                      "id INT NOT NULL AUTO_INCREMENT,"
                                      "Identity VARCHAR(100) NOT NULL,"
                                      "Name VARCHAR(100),"
                                      "PubName VARCHAR(100),"
                                      "Version VARCHAR(100),"
                                      "Date VARCHAR(100),"
                                      "CreateTime DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                                      "PRIMARY KEY (id)"
                                      ")";
                    if (0 != mysql_query(conn, sql)){
                        break;
                    }
                }
                if (NULL == row5){
                    const char* sql = "create table strategy("
                                      "id INT NOT NULL AUTO_INCREMENT,"
                                      "Identity VARCHAR(100) NOT NULL,"
                                      "SgyID VARCHAR(100),"
                                      "name VARCHAR(100),"
                                      "des VARCHAR(100),"
                                      "setE VARCHAR(100),"
                                      "new TINYINT(1),"
                                      "CreateTime DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                                      "PRIMARY KEY (id)"
                                      ")";

                    if (0 != mysql_query(conn, sql)){
                        fprintf(stderr, "%s\n", mysql_error(conn));
                        break;
                    }
                }
                if (NULL == row6){
                    const char* sql = "create table bwform("
                                      "id INT NOT NULL AUTO_INCREMENT,"
                                      "Identity VARCHAR(100) NOT NULL,"
                                      "procname VARCHAR(100),"
                                      "des VARCHAR(100),"
                                      "enable TINYINT(1),"
                                      "CreateTime DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                                      "PRIMARY KEY (id)"
                                      ")";
                    if (0 != mysql_query(conn, sql)){
                        fprintf(stderr, "%s\n", mysql_error(conn));
                        break;
                    }
                }
                bSuccess = true;
                break;
            }
            if (bSuccess) {
                ret = true;
            }
        }

        mysql_free_result(result1);
        mysql_free_result(result2);
        mysql_free_result(result3);
    }

    return ret;
}

inline std::string& replace_str(std::string& str, const std::string& to_replaced, const std::string& newchars)
{
    for(std::string::size_type pos(0); pos != std::string::npos; pos += newchars.length())
    {
        pos = str.find(to_replaced,pos);
        if(pos != std::string::npos)
            str.replace(pos,to_replaced.length(),newchars);
        else
            break;
    }
    return str;
}

void prmysql::CheckFileToDB(std::map<std::string, std::string> &hwinfo,
                   std::vector<ST_SHIELD> sdinfo, std::vector<ST_SERVICE> svcinfo,
                   std::vector<ST_SOFTWARE> swinfo)
{
    if (bConnected)
    {
        int res;
        char sql[1024];

        memset(sql, 0, sizeof(sql));
        const char* ft_hw_info = "insert into checkinfo_hardware("
                                 "Identity,"
                                 "MachineName,"
                                 "MotherboardID,"
                                 "CPUType,"
                                 "CPUNumber,"
                                 "MemoryCapacity,"
                                 "MemoryNumber,"
                                 "DiskType,"
                                 "DiskCapacity,"
                                 "DiskNumber,"
                                 "DiskPartition,"
                                 "LocalIP,"
                                 "VideoCardType,"
                                 "VideoCardNumber"
                                 ")"
                                 "values("
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s',"
                                 "'%s'"
                                 ")";
        sprintf(sql, ft_hw_info,
                ID.c_str(),
                replace_str(hwinfo["MachineName"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["MotherboardID"],"\\", "\\\\").c_str(),
                replace_str(hwinfo["CPUType"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["CPUNumber"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["MemoryCapacity"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["MemoryNumber"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["DiskType"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["DiskCapacity"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["DiskNumber"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["DiskPartition"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["LocalIP"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["VideoCardType"], "\\", "\\\\").c_str(),
                replace_str(hwinfo["VideoCardNumber"], "\\", "\\\\").c_str()
                );
        res = mysql_query(conn, sql);
        if (res) {
            fprintf(stderr, "%s\n", mysql_error(conn));
        }

        for(std::vector<ST_SHIELD>::iterator it = sdinfo.begin(); it != sdinfo.end(); it++) {
            memset(sql, 0, sizeof(sql));
            const char* ft_sd_info = "insert into checkinfo_shield("
                                     "Identity,"
                                     "displayName,"
                                     "pathToSignedProductExe,"
                                     "status"
                                     ")"
                                     "values("
                                     "'%s',"
                                     "'%s',"
                                     "'%s',"
                                     "'%s'"
                                     ")";
            sprintf(sql, ft_sd_info,
                    ID.c_str(),
                    replace_str((*it).displayName, "\\", "\\\\").c_str(),
                    replace_str((*it).pathToSignedProductExe, "\\", "\\\\").c_str(),
                    replace_str((*it).status, "\\", "\\\\").c_str()
                    );
            res = mysql_query(conn, sql);
            if (res) {
                fprintf(stderr, "%s\n", mysql_error(conn));
            }
        }

        for(std::vector<ST_SERVICE>::iterator it = svcinfo.begin(); it != svcinfo.end(); it++) {


            memset(sql, 0, sizeof(sql));
            const char* ft_svc_info = "insert into checkinfo_service("
                                      "Identity,"
                                      "DisplayName,"
                                      "ServiceName,"
                                      "ServiceType,"
                                      "status"
                                      ")"
                                      "values("
                                      "'%s',"
                                      "'%s',"
                                      "'%s',"
                                      "'%s',"
                                      "'%s'"
                                      ")";
            sprintf(sql, ft_svc_info,
                    ID.c_str(),
                    replace_str((*it).DisplayName, "\\", "\\\\").c_str(),
                    replace_str((*it).ServiceName, "\\", "\\\\").c_str(),
                    replace_str((*it).ServiceType, "\\", "\\\\").c_str(),
                    replace_str((*it).status, "\\", "\\\\").c_str()
                    );
            res = mysql_query(conn, sql);
            if (res) {
                fprintf(stderr, "%s\n", mysql_error(conn));
            }
        }

        for(std::vector<ST_SOFTWARE>::iterator it = swinfo.begin(); it != swinfo.end(); it++) {
            memset(sql, 0, sizeof(sql));
            const char *ft_sw_info = "insert into checkinfo_software("
                                     "Identity,"
                                     "Name,"
                                     "PubName,"
                                     "Version,"
                                     "Date"
                                     ")"
                                     "values("
                                     "'%s',"
                                     "'%s',"
                                     "'%s',"
                                     "'%s',"
                                     "'%s'"
                                     ")";
            sprintf(sql, ft_sw_info,
                    ID.c_str(),
                    replace_str((*it).Name, "\\", "\\\\").c_str(),
                    replace_str((*it).PubName, "\\", "\\\\").c_str(),
                    replace_str((*it).Version, "\\", "\\\\").c_str(),
                    replace_str((*it).Date, "\\", "\\\\").c_str()
                    );
            res = mysql_query(conn, sql);
            if (res) {
                fprintf(stderr, "%s\n", mysql_error(conn));
            }
        }
    }
}

std::vector<ST_STRATEGY> prmysql::GetStrategyFromDB() {
    std::vector<ST_STRATEGY> ret;

    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *ft_sql = "select SgyID name des setE from strategy "
                      "where Identity=%s new=1";

    char sql[256] = {0};
    sprintf(sql, ft_sql, replace_str(ID, "\\", "\\\\").c_str());

    int r = mysql_query(conn, sql);

    res = mysql_use_result(conn);

    while(NULL != (row = mysql_fetch_row(res)))
    {
        ST_STRATEGY st_t;

        st_t.SgyID = row[0];
        st_t.name = row[1];
        st_t.des = row[2];
        st_t.set = row[3];

        ret.push_back(st_t);
    }

    mysql_free_result(res);//释放记录集

    return ret;
}

std::vector<ST_BWFORM> prmysql::GetBWFormFromDB() {
    std::vector<ST_BWFORM> ret;

    MYSQL_RES *res;
    MYSQL_ROW row;

    const char* ft_sql = "select procname des from bwform "
                      "where Identity=%s enable=1";

    char sql[256] = {0};
    sprintf(sql, ft_sql, replace_str(ID, "\\", "\\\\").c_str());

    int r = mysql_query(conn, sql);

    res = mysql_use_result(conn);

    while(NULL != (row = mysql_fetch_row(res)))
    {
        ST_BWFORM st_t;

        st_t.procname = row[0];
        st_t.des = row[1];

        ret.push_back(st_t);
    }

    mysql_free_result(res);//释放记录集

    return ret;
}