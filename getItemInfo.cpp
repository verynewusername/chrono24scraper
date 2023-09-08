#include "Scraper.h"

ItemStruct Scraper::getItemInfo(std::string const &content) {

    // ItemStruct itemStruct = {
    //     listingCode: "NULL",
    //     brand: "NULL",
    //     model: "NULL",
    //     referenceNumber: "NULL",
    //     movement: "NULL",
    //     caseMaterial: "NULL",
    //     braceletMaterial: "NULL",
    //     condition: "NULL",
    //     yearOfProduction: "NULL",
    //     scopeOfDelivery: "NULL",
    //     gender: "NULL",
    //     price: "NULL",
    //     numberOfJewels: "NULL",
    //     dial: "NULL",
    //     url: "NULL"
    // };

    ItemStruct itemStruct;

    // Initialize libxml2
    xmlInitParser();

    // Parse the HTML content
    htmlDocPtr doc = htmlReadDoc(reinterpret_cast<const xmlChar*>(content.c_str()), nullptr, nullptr, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc) {
        // Start extracting page numbers from the document
        extractValues(xmlDocGetRootElement(doc), &itemStruct);

        // Free the document
        xmlFreeDoc(doc);
    }

    // Cleanup libxml2
    xmlCleanupParser();

    return itemStruct;
}