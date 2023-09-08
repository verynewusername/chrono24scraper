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
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res);

            res = curl_easy_perform(curl);
            if (res != CURLE_OK) 
                throw std::runtime_error(curl_easy_strerror(res));
        } 
        catch (std::exception const &e) 
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        curl_easy_cleanup(curl);

        std::vector<std::string> tempTargetList = scraper.getPageLinks(readBuffer);

        if (tempTargetList.size() == 0)
            throw std::runtime_error("tempTargetList is empty.");

        flushTargetListBuffer();

        for (auto &i : tempTargetList)
            targetListBuffer.push_back(i);

    }
    else 
    {
        std::cout << "No more listing pages to crawl." << std::endl;
    }
}