//
// Created by zhangcl on 12/25/18.
//

#include "prmysql.h"

void prmysql::init()
{
    if (conn) {
        mysql_close(conn);
        conn = NULL;
    }
    conn = mysql_init(NULL);
}

prmysql::prmysql(const char* serverIP, const char* userName, const char* passWord)
{
    conn = mysql_init(NULL);

    my_db = "czz_db";

    server = serverIP;
    user = userName;
    password = passWord;

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
}

prmysql::~prmysql()
{
    if (conn)
        mysql_close(conn);
    mysql_library_end();
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
                                      "MachineName VARCHAR(100) NOT NULL,"
                                      "MotherboardID VARCHAR(100) NOT NULL,"
                                      "CPUType VARCHAR(100) NOT NULL,"
                                      "CPUNumber VARCHAR(100) NOT NULL,"
                                      "MemoryCapacity VARCHAR(100) NOT NULL,"
                                      "MemoryNumber VARCHAR(100) NOT NULL,"
                                      "DiskType VARCHAR(100) NOT NULL,"
                                      "DiskCapacity VARCHAR(100) NOT NULL,"
                                      "DiskNumber VARCHAR(100) NOT NULL,"
                                      "DiskPartition VARCHAR(100) NOT NULL,"
                                      "LocalIP VARCHAR(100) NOT NULL,"
                                      "VideoCardType VARCHAR(100) NOT NULL,"
                                      "VideoCardNumber VARCHAR(100) NOT NULL,"
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
                                      "displayName VARCHAR(100) NOT NULL,"
                                      "pathToSignedProductExe VARCHAR(100) NOT NULL,"
                                      "status VARCHAR(100) NOT NULL,"
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
                                      "DisplayName VARCHAR(100) NOT NULL,"
                                      "ServiceName VARCHAR(100) NOT NULL,"
                                      "ServiceType VARCHAR(100) NOT NULL,"
                                      "status VARCHAR(100) NOT NULL,"
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
                                      "Name VARCHAR(100) NOT NULL,"
                                      "PubName VARCHAR(100) NOT NULL,"
                                      "Version VARCHAR(100) NOT NULL,"
                                      "Date VARCHAR(100) NOT NULL,"
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
                                      "SgyID VARCHAR(100) NOT NULL,"
                                      "name VARCHAR(100) NOT NULL,"
                                      "des VARCHAR(100) NOT NULL,"
                                      "setE VARCHAR(100) NOT NULL,"
                                      "new TINYINT(1) NOT NULL,"
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
                                      "procname VARCHAR(100) NOT NULL,"
                                      "des VARCHAR(100) NOT NULL,"
                                      "enable TINYINT(1) NOT NULL,"
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