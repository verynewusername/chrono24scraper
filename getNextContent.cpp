#include "Crawler.h"

bool Crawler::getNextContent() 
{
    contentBuffer.clear();

    if (targetListBuffer.size() == 0 && listingPageIndex < num_listing_pages) 
        getNextTargetListBuffer();
    else if (targetListBuffer.size() == 0 && listingPageIndex == num_listing_pages) {
        std::cout << "LOG: No more targets to crawl." << std::endl;
        return false;
    } else if (targetListBuffer.size() != 0)
        getNextContentBuffer();
    else
        throw std::runtime_error("LOG: targetListBuffer is empty.");
    

    itemBuffer = scraper.getItemInfo(contentBuffer);
    itemBuffer.url = currentTarget;

    return true;
}