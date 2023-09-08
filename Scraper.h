#ifndef SCRAPER_H
#define SCRAPER_H

#include <iostream>         // std::cout
#include <string>           // std::string
#include <vector>           // std::vector
#include <libxml/HTMLparser.h>
#include <regex>   
#include "itemStruct.h"     // itemStruct

class Scraper
{

public:
    Scraper() {};
    ~Scraper() {};

    int getNumberOfPages(std::string const &content);

    std::vector<std::string> getPageLinks(std::string const &content);

    ItemStruct getItemInfo(std::string const &content);

private:

    int extractPageNumber(xmlNode* node, int maxPage);

    void extractURLs(xmlNode* node, std::vector<std::string> &itemURLs);

    void extractValues(xmlNode* node, ItemStruct *itemStruct);

    std::string trimWhitespace(std::string str);
};

#endif // Path: Scraper.h
