#include "Scraper.h"

int Scraper::extractPageNumber(xmlNode* node, int maxPage) {
    for (xmlNode* curNode = node; curNode; curNode = curNode->next) {
        if (curNode->type == XML_ELEMENT_NODE && xmlStrcmp(curNode->name, reinterpret_cast<const xmlChar*>("a")) == 0) {
            xmlChar* href = xmlGetProp(curNode, reinterpret_cast<const xmlChar*>("href"));
            if (href) {
                std::string hrefStr = reinterpret_cast<const char*>(href);
                xmlFree(href);

                // Check if the href attribute contains "showpage=" and is a number
                size_t pos = hrefStr.find("showpage=");
                if (pos != std::string::npos) {
                    try {
                        int page = std::stoi(hrefStr.substr(pos + 9));
                        if (page > maxPage) {
                            maxPage = page;
                        }
                    } catch (const std::invalid_argument&) {
                        // Ignore invalid page numbers
                    }
                }
            }
        }

        // Recursively process child nodes
        maxPage = extractPageNumber(curNode->children, maxPage);
    }

    return maxPage;
}