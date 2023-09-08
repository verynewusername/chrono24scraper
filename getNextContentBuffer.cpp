#include "Crawler.h"

void Crawler::getNextContentBuffer()
{

    if (targetListBuffer.size() == 0)
        throw std::runtime_error("targetListBuffer is empty.");

    if (targetListBuffer.size() != 0) {
        currentTarget = targetListBuffer.back();
        targetListBuffer.pop_back();
    }

    if (currentTarget != "") {
        CURL *curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if (!curl)
            throw std::runtime_error("cURL initialization failed.");

        try 
        {
            curl_easy_setopt(curl, CURLOPT_URL, currentTarget.c_str());
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

        contentBuffer = readBuffer;
    }
    else 
    {
        std::cout << "No more targets to crawl." << std::endl;
    }
}
