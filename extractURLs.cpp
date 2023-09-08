#include "Scraper.h"

void Scraper::extractURLs(xmlNode* node, std::vector<std::string>& itemURLs) {
    for (xmlNode* curNode = node; curNode; curNode = curNode->next) {
        if (curNode->type == XML_ELEMENT_NODE && xmlStrcmp(curNode->name, reinterpret_cast<const xmlChar*>("script")) == 0) {
            xmlChar* jsonContent = xmlNodeGetContent(curNode);
            if (jsonContent) {
                // Convert the JSON content to a string
                std::string jsonString = reinterpret_cast<const char*>(jsonContent);
                xmlFree(jsonContent);

                // Use regular expressions to find URLs within the JSON content
                std::regex urlRegex("https://www\\.chrono24\\.com/[^\"\\s]+");
                std::smatch urlMatches;
                std::string::const_iterator searchStart(jsonString.cbegin());

                while (std::regex_search(searchStart, jsonString.cend(), urlMatches, urlRegex)) {
                    itemURLs.push_back(urlMatches[0]);
                    searchStart = urlMatches.suffix().first;
                }
            }
        }

        // Recursively process child nodes
        extractURLs(curNode->children, itemURLs);
    }
}