//
// Created by zhangcl on 12/11/18.
//

#include "prxml.h"

// std::cout << "Hello, World!" << std::endl;
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <iostream>
#include <unistd.h>

#include "prmysql.h"

using namespace std;

prxml::prxml() {

}

prxml::~prxml() {

}

int prxml::Parse(const char* szDocName) {
    xmlDocPtr doc;           //定义解析文件指针
    xmlNodePtr curNode;      //定义结点指针(你需要它在各个结点间移动)
    xmlChar *szKey;          //临时字符串变量

    doc = xmlReadFile(szDocName, "UTF-8", XML_PARSE_RECOVER); //解析文件
    if (NULL == doc)
    {
        fprintf(stderr,"Document not parsed successfully. \n");
        return -1;
    }

    curNode = xmlDocGetRootElement(doc); //确定文件根元素
    if (NULL == curNode)
    {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc);
        return -1;
    }

    /*我们需要确认文件是正确的类型。“root”是在这个示例中使用文件的根类型。*/
    if (xmlStrcmp(curNode->name, BAD_CAST "Environment_Checked_info"))
    {
        fprintf(stderr,"document of the wrong type, root node != root");
        xmlFreeDoc(doc);
        return -1;
    }

    xmlNodePtr tapGroup = curNode->xmlChildrenNode;
    while(tapGroup != NULL)
    {
        if (tapGroup->type == XML_TEXT_NODE)
        {
            tapGroup = tapGroup->next;
            continue;
        }
        if ((!xmlStrcmp(tapGroup->name, (const xmlChar *)"HardwareInfo")))
        {
            xmlNodePtr xmlSecond = tapGroup->xmlChildrenNode;

            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "MachineName"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["MachineName"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "MotherboardID"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["MotherboardID"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "CPUType"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["CPUType"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "CPUNumber"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["CPUNumber"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "MemoryCapacity"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["MemoryCapacity"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "MemoryNumber"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["MemoryNumber"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "DiskType"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["DiskType"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "DiskCapacity"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["DiskCapacity"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "DiskNumber"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["DiskNumber"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "DiskPartition"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["DiskPartition"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "LocalIP"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["LocalIP"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "VideoCardType"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["VideoCardType"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "VideoCardNumber"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
                    hardwareinfo["VideoCardNumber"] = std::string((char *) szValue);
                    xmlFree(szValue);
                }
            }
        }
        if ((!xmlStrcmp(tapGroup->name, (const xmlChar *)"ShieldInfo")))
        {
            xmlNodePtr xmlSecond = tapGroup->xmlChildrenNode;

            while(xmlSecond)
            {
                if (xmlSecond->type == XML_TEXT_NODE) {
                    xmlSecond = xmlSecond->next;
                    if (!xmlSecond)
                        break;
                }
                ST_SHIELD st_t;
                if (xmlHasProp(xmlSecond, BAD_CAST "displayName"))
                {
                    xmlChar* szDisplayName = xmlGetProp(xmlSecond, BAD_CAST "displayName");
                    st_t.displayName = std::string((char *)szDisplayName);
                    xmlFree(szDisplayName);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "pathToSignedProductExe"))
                {
                    xmlChar* szPathToSignedProductExe = xmlGetProp(xmlSecond, BAD_CAST "pathToSignedProductExe");
                    st_t.pathToSignedProductExe = std::string((char *)szPathToSignedProductExe);
                    xmlFree(szPathToSignedProductExe);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "status"))
                {
                    xmlChar* szstatus = xmlGetProp(xmlSecond, BAD_CAST "status");
                    st_t.status = std::string((char *)szstatus);
                    xmlFree(szstatus);
                }
                shieldinfo.push_back(st_t);
                xmlSecond = xmlSecond->next;
            }
        }
        if ((!xmlStrcmp(tapGroup->name, (const xmlChar *)"SysServiceInfo")))
        {
            xmlNodePtr xmlSecond = tapGroup->xmlChildrenNode;

            while(xmlSecond)
            {
                if (xmlSecond->type == XML_TEXT_NODE) {
                    xmlSecond = xmlSecond->next;
                    if (!xmlSecond)
                        break;
                }
                ST_SERVICE st_t;
                if (xmlHasProp(xmlSecond, BAD_CAST "DisplayName"))
                {
                    xmlChar* szDisplayName = xmlGetProp(xmlSecond, BAD_CAST "DisplayName");
                    st_t.DisplayName = std::string((char *) szDisplayName);
                    xmlFree(szDisplayName);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "ServiceName"))
                {
                    xmlChar* szServiceName = xmlGetProp(xmlSecond, BAD_CAST "ServiceName");
                    st_t.ServiceName = std::string((char *) szServiceName);
                    xmlFree(szServiceName);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "ServiceType"))
                {
                    xmlChar* szServiceType = xmlGetProp(xmlSecond, BAD_CAST "ServiceType");
                    st_t.ServiceType = std::string((char *) szServiceType);
                    xmlFree(szServiceType);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "status"))
                {
                    xmlChar* szStatus = xmlGetProp(xmlSecond, BAD_CAST "status");
                    st_t.status = std::string((char *) szStatus);
                    xmlFree(szStatus);
                }
                serviceinfo.push_back(st_t);
                xmlSecond = xmlSecond->next;
            }
        }
        if ((!xmlStrcmp(tapGroup->name, (const xmlChar *)"SysSoftwareInfo")))
        {
            xmlNodePtr xmlSecond = tapGroup->xmlChildrenNode;

            while(xmlSecond)
            {
                if (xmlSecond->type == XML_TEXT_NODE) {
                    xmlSecond = xmlSecond->next;
                    if (!xmlSecond)
                        break;
                }
                ST_SOFTWARE st_t;
                if (xmlHasProp(xmlSecond, BAD_CAST "Name"))
                {
                    xmlChar* szName = xmlGetProp(xmlSecond, BAD_CAST "Name");
                    st_t.Name = std::string((char *) szName);
                    xmlFree(szName);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "PubName"))
                {
                    xmlChar* szPubName = xmlGetProp(xmlSecond, BAD_CAST "PubName");
                    st_t.PubName = std::string((char *) szPubName);
                    xmlFree(szPubName);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "Version"))
                {
                    xmlChar* szVersion = xmlGetProp(xmlSecond, BAD_CAST "Version");
                    st_t.Version = std::string((char *) szVersion);
                    xmlFree(szVersion);
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "Date"))
                {
                    xmlChar* szDate = xmlGetProp(xmlSecond, BAD_CAST "Date");
                    st_t.Date = std::string((char *) szDate);
                    xmlFree(szDate);
                }
                softwareinfo.push_back(st_t);
                xmlSecond = xmlSecond->next;
            }
        }
        tapGroup = tapGroup->next;
    }

    xmlFreeDoc(doc);
    return 1;
}

void prxml::GenerateFileStrategy(const char* ID, std::vector<ST_STRATEGY> v_st_t) {
    char path[256] = {0};
    sprintf(path, "./%s", ID);

    char pathfile[256] = {0};
    sprintf(pathfile, "%s/strategy_info.xml", path);

    xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
    xmlNodePtr root_node = xmlNewNode(NULL, BAD_CAST "strategy_info");

    xmlDocSetRootElement(doc, root_node);

    xmlNodePtr xmlSub;

    for (std::vector<ST_STRATEGY>::iterator it = v_st_t.begin(); it != v_st_t.end(); it++) {
        xmlSub = xmlNewNode(NULL, BAD_CAST "strategy");
        xmlAddChild(root_node, xmlSub);

        xmlNewProp(xmlSub, BAD_CAST "id", BAD_CAST (*it).SgyID.c_str());
        xmlNewProp(xmlSub, BAD_CAST "name", BAD_CAST (*it).name.c_str());
        xmlNewProp(xmlSub, BAD_CAST "des", BAD_CAST (*it).des.c_str());
        xmlNewProp(xmlSub, BAD_CAST "set", BAD_CAST (*it).set.c_str());
    }

    if (0 < v_st_t.size()) {
        int nRel = xmlSaveFile(pathfile, doc);
    }
    else {
        int ret = access(pathfile, F_OK);
        if (0 == ret) {
            remove(pathfile);
        }
    }

    xmlFreeDoc(doc);
}

void prxml::GenerateFileBWForm(const char* ID, std::vector<ST_BWFORM> v_st_t) {
    char path[256] = {0};
    sprintf(path, "./%s", ID);

    char pathfile[256] = {0};
    sprintf(pathfile, "%s/black_white_form_info.xml", path);

    xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
    xmlNodePtr root_node = xmlNewNode(NULL, BAD_CAST "bwsoftware_info");

    xmlDocSetRootElement(doc, root_node);

    xmlNodePtr xmlSub;

    for (std::vector<ST_BWFORM>::iterator it = v_st_t.begin(); it != v_st_t.end(); it++) {
        xmlSub = xmlNewNode(NULL, BAD_CAST "bwsoftware");
        xmlAddChild(root_node, xmlSub);

        xmlNewProp(xmlSub, BAD_CAST "procname", BAD_CAST (*it).procname.c_str());
        xmlNewProp(xmlSub, BAD_CAST "des", BAD_CAST (*it).des.c_str());
    }

    if (0 < v_st_t.size()) {
        int nRel = xmlSaveFile(pathfile, doc);
    }
    else {
        int ret = access(pathfile, F_OK);
        if (0 == ret) {
            remove(pathfile);
        }
    }

    xmlFreeDoc(doc);
}