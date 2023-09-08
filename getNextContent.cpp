#include "Crawler.h"

bool Crawler::getNextContent() 
{
    contentBuffer.clear();

    if (targetListBuffer.size() == 0 && listingPageIndex < num_listing_pages) {
        getNextTargetListBuffer();
    } else if (targetListBuffer.size() == 0 && listingPageIndex == num_listing_pages) {
        std::cout << "LOG: No more targets to crawl." << std::endl;
        return false;
    }

    getNextContentBuffer();

    itemBuffer = scraper.getItemInfo(contentBuffer);
    itemBuffer.url = currentTarget;

    return true;
}