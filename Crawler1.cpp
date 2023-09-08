#include "Crawler.h"

Crawler::Crawler()
:
    targetURLPart1("https://www.chrono24.com/search/index.htm?currencyId=USD&dosearch=true&manufacturerIds=221&manufacturerIds=247&manufacturerIds=127&manufacturerIds=18&manufacturerIds=438&manufacturerIds=194&maxAgeInDays=0&pageSize=120&redirectToSearchIndex=true&resultview=block&searchexplain=1&showpage="),
    targetURLPart2("&sortorder=0&specials=103&specials=104&usedOrNew=new&watchTypes=U"),
    counter(0),
    num_listing_pages(0),
    listingPageIndex(1),
    targetListBuffer(),
    contentBuffer(""),
    currentTarget(""),
    scraper()
{
    getNumberOfListingPages();
}