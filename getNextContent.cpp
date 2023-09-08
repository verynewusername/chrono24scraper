#include "Crawler.h"

bool Crawler::getNextContent() 
{
    contentBuffer.clear();

    if (targetListBuffer.size() == 0 && listingPageIndex < num_listing_pages)
        getNextTargetListBuffer();
    else 
        std::cout << "No more targets to crawl." << std::endl;
        return false;
    

    itemBuffer = scraper.getItemInfo(contentBuffer);

    return true;
}