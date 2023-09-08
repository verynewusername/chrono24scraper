#include "Scraper.h"


int Scraper::getNumberOfPages(std::string const &content)
{
   int maxPage = 0;

    // Initialize libxml2
    xmlInitParser();

    // Parse the HTML content
    htmlDocPtr doc = htmlReadDoc(reinterpret_cast<const xmlChar*>(content.c_str()), nullptr, nullptr, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc) {
        // Start extracting page numbers from the document
        maxPage = extractPageNumber(xmlDocGetRootElement(doc), maxPage);

        // Free the document
        xmlFreeDoc(doc);
    }

    // Cleanup libxml2
    xmlCleanupParser();

    return maxPage;
}
