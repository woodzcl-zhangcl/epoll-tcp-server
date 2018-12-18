//
// Created by zhangcl on 12/11/18.
//

#include "prxml.h"

// std::cout << "Hello, World!" << std::endl;
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <iostream>
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
                }
            }

            xmlSecond = xmlSecond->next;
            if (xmlSecond->type == XML_TEXT_NODE)
                xmlSecond = xmlSecond->next;
            if (!xmlStrcmp(xmlSecond->name, BAD_CAST "MemoryCapatity"))
            {
                if (xmlHasProp(xmlSecond, BAD_CAST "Value"))
                {
                    xmlChar* szValue = xmlGetProp(xmlSecond, BAD_CAST "Value");
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
                if (xmlHasProp(xmlSecond, BAD_CAST "displayName"))
                {
                    xmlChar* szDisplayName = xmlGetProp(xmlSecond, BAD_CAST "displayName");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "pathToSignedProductExe"))
                {
                    xmlChar* szPathToSignedProductExe = xmlGetProp(xmlSecond, BAD_CAST "pathToSignedProductExe");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "pathToSignedProductExe"))
                {
                    xmlChar* szstatus = xmlGetProp(xmlSecond, BAD_CAST "status");
                }
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
                if (xmlHasProp(xmlSecond, BAD_CAST "DisplayName"))
                {
                    xmlChar* szDisplayName = xmlGetProp(xmlSecond, BAD_CAST "DisplayName");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "ServiceName"))
                {
                    xmlChar* szServiceName = xmlGetProp(xmlSecond, BAD_CAST "ServiceName");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "ServiceType"))
                {
                    xmlChar* szServiceType = xmlGetProp(xmlSecond, BAD_CAST "ServiceType");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "status"))
                {
                    xmlChar* szStatus = xmlGetProp(xmlSecond, BAD_CAST "status");
                }
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
                if (xmlHasProp(xmlSecond, BAD_CAST "Name"))
                {
                    xmlChar* szName = xmlGetProp(xmlSecond, BAD_CAST "Name");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "PubName"))
                {
                    xmlChar* szPubName = xmlGetProp(xmlSecond, BAD_CAST "PubName");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "Version"))
                {
                    xmlChar* szVersion = xmlGetProp(xmlSecond, BAD_CAST "Version");
                }
                if (xmlHasProp(xmlSecond, BAD_CAST "Date"))
                {
                    xmlChar* szDate = xmlGetProp(xmlSecond, BAD_CAST "Date");
                }
                xmlSecond = xmlSecond->next;
            }
        }
        tapGroup = tapGroup->next;
    }

    xmlFreeDoc(doc);
    return 1;
}