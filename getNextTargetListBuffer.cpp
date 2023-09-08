#include "Crawler.h"

void Crawler::getNextTargetListBuffer()
{
    if (targetURLPart1 == "" && targetURLPart2 == "")
        throw std::runtime_error("targetURLParts are empty.");

    if (++listingPageIndex <= num_listing_pages)
    {
        CURL *curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if (!curl)
            throw std::runtime_error("cURL initialization failed.");

        try 
        {
            curl_easy_setopt(curl, CURLOPT_URL, (targetURLPart1 + std::to_string(listingPageIndex) + targetURLPart2).c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            if (res != CURLE_OK) 
                throw std::runtime_error(curl_easy_strerror(res));
        } 
        catch (std::exception const &e) 
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        curl_easy_cleanup(curl);

        targetListBuffer = scraper.getPageLinks(readBuffer);

        if (targetListBuffer.size() == 0)
            throw std::runtime_error("tempTargetList is empty.");

        std::cout << "LOG: " << targetListBuffer.size() << " URLs found on the current query page" << std::endl;
        std::cout << "LOG: Crawling page index: " << listingPageIndex << std::endl;

        // //print the list
        // for (auto const &i : tempTargetList)
        //     std::cout << i << std::endl;

    }
    else 
    {
        std::cout << "No more listing pages to crawl." << std::endl;
    }
}