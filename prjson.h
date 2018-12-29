//
// Created by zhangcl on 12/28/18.
//

#ifndef CZZ_SERV_PRJSON_H
#define CZZ_SERV_PRJSON_H

#include "json.hpp"
// for convenience
using json = nlohmann::json;

class prjson {
public:
    prjson();
    virtual ~prjson();
};


#endif //CZZ_SERV_PRJSON_H
