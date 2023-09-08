#include "Crawler.h"

void Crawler::getNumberOfListingPages()
{
    if (targetURLPart1 == "" && targetURLPart2 == "")
        throw std::runtime_error("targetURLParts are empty.");

    std::cout << "LOG: Getting number of listing pages...\n";


    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (!curl)
        throw std::runtime_error("cURL initialization failed.");

    try 
    {
        curl_easy_setopt(curl, CURLOPT_URL, (targetURLPart1 + "1" + targetURLPart2).c_str());
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

    int temp = scraper.getNumberOfPages(readBuffer);
    
    if (temp == 0)
        throw std::runtime_error("Number of listing pages is 0.");
    else
        num_listing_pages = temp;

    std::cout << "LOG: Number of listing pages: " << num_listing_pages << std::endl;

}