//
// Created by zhangcl on 12/11/18.
//

#ifndef CZZ_SERV_PRXML_H
#define CZZ_SERV_PRXML_H

#include <vector>
#include <map>

struct ST_SHIELD
{
    std::string displayName;
    std::string pathToSignedProductExe;
    std::string status;
};

struct ST_SERVICE
{
    std::string DisplayName;
    std::string ServiceName;
    std::string ServiceType;
    std::string status;
};

struct ST_SOFTWARE
{
    std::string Name;
    std::string PubName;
    std::string Version;
    std::string Date;
};

class prxml {
public:
    std::map<std::string, std::string> hardwareinfo;
    std::vector<ST_SHIELD> shieldinfo;
    std::vector<ST_SERVICE> serviceinfo;
    std::vector<ST_SOFTWARE> softwareinfo;
public:
    prxml();
    virtual ~prxml();
public:
    int Parse(const char* szDocName);
};


#endif //CZZ_SERV_PRXML_H
