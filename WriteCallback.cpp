#include "Crawler.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) 
{
    size_t total_size = size * nmemb;
    std::string* response = static_cast<std::string*>(userp);
    response->append(static_cast<char*>(contents), total_size);
    return total_size;
}
