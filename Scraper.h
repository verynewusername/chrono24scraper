#ifndef SCRAPER_H
#define SCRAPER_H

#include <iostream>         // std::cout
#include <string>           // std::string
#include <vector>           // std::vector
#include "itemStruct.h"     // itemStruct
#include <libxml/HTMLparser.h>

class Scraper
{

public:
    Scraper() {};
    ~Scraper() {};

    int getNumberOfPages(std::string const &content);

    int extractPageNumber(xmlNode* node, int maxPage);

    std::vector<std::string> getPageLinks(std::string const &content)
    {
        std::vector<std::string> pageLinks;
        return pageLinks;
    }

    ItemStruct getItemInfo(std::string const &content) {
        ItemStruct item;
        return item;
    }

};

#endif // Path: Scraper.h
