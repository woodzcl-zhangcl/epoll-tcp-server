//
// Created by zhangcl on 12/11/18.
//

#ifndef CZZ_SERV_PRXML_H
#define CZZ_SERV_PRXML_H


class prxml {
public:
    prxml();
    virtual ~prxml();
public:
    int Parse(const char* szDocName);
};


#endif //CZZ_SERV_PRXML_H
