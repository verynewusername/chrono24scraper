#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>     // std::cout
#include <string>       // std::string
#include <curl/curl.h>  // curl
#include <vector>       // std::vector
#include "itemStruct.h" // ItemStruct
#include "Scraper.h"    // Scraper

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

class Crawler
{

public:
    Crawler();
    ~Crawler();

    bool getNextContent();

    ItemStruct getItemBuffer();
    
private:
    std::string targetURLPart1;
    std::string targetURLPart2;

    int counter;                        // Counter for the number of URLs crawled

    int num_listing_pages;              // Number of listing pages
    int listingPageIndex;               // Index of the listing page

    Scraper scraper;                    // Scraper object

    std::vector<std::string> targetListBuffer;// List of URLs to crawl

    std::string currentTarget;          // Current target URL

    std::string contentBuffer;          // Content of the target URL

    ItemStruct itemBuffer;              // ItemStruct object



    void getNumberOfListingPages();

    void getNextTargetListBuffer();

    void getNextContentBuffer();


    void flushTargetListBuffer();       // Flush the targetListBuffer

};

#endif // Path: Crawler.h
