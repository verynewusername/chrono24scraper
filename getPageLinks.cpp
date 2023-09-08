#include "Scraper.h"

std::vector<std::string> Scraper::getPageLinks(std::string const &content){

    std::vector<std::string> itemURLs;

    // Initialize libxml2
    xmlInitParser();

    // Parse the HTML content
    htmlDocPtr doc = htmlReadDoc(reinterpret_cast<const xmlChar*>(content.c_str()), nullptr, nullptr, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc) {
        // Start extracting item URLs from the document
        extractURLs(xmlDocGetRootElement(doc), itemURLs);

        // Free the document
        xmlFreeDoc(doc);
    }

    // Cleanup libxml2
    xmlCleanupParser();

    // std::cout << "Found " << itemURLs.size() << " item URLs." << std::endl;

    return std::move(itemURLs);

}