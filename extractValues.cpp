#include "Scraper.h"

void Scraper::extractValues(xmlNode* node, ItemStruct &itemStruct) {
    for (xmlNode* curNode = node; curNode; curNode = curNode->next) {
        if (curNode->type == XML_ELEMENT_NODE && xmlStrcmp(curNode->name, reinterpret_cast<const xmlChar*>("td")) == 0) {
            xmlChar* classAttr = xmlGetProp(curNode, reinterpret_cast<const xmlChar*>("class"));
            if (classAttr && xmlStrcmp(classAttr, reinterpret_cast<const xmlChar*>("p-r-2")) == 0) {
                // This <td> element has class "p-r-2"
                xmlNode* strongNode = curNode->children;
                if (strongNode && xmlStrcmp(strongNode->name, reinterpret_cast<const xmlChar*>("strong")) == 0) {
                    // The content of the <strong> tag is the key
                    std::string key = reinterpret_cast<const char*>(xmlNodeGetContent(strongNode));

                    // The content of the next <td> tag is the value
                    std::string value = reinterpret_cast<const char*>(xmlNodeGetContent(strongNode->next));
                    
                    // Store the key-value pair
                    //values.emplace_back(key, value);

                    if (key == "Listing code")
                        itemStruct.listingCode = value;
                    else if (key == "Brand")
                        itemStruct.brand = value;
                    else if (key == "Model")
                        itemStruct.model = value;
                    else if (key == "Reference number")
                        itemStruct.referenceNumber = value;
                    else if (key == "Movement")
                        itemStruct.movement = value;
                    else if (key == "Case material")
                        itemStruct.caseMaterial = value;
                    else if (key == "Bracelet material")
                        itemStruct.braceletMaterial = value;
                    else if (key == "Condition")
                        itemStruct.condition = value;
                    else if (key == "Year of production")
                        itemStruct.yearOfProduction = value;
                    else if (key == "Scope of delivery")
                        itemStruct.scopeOfDelivery = value;
                    else if (key == "Gender")
                        itemStruct.gender = value;
                    else if (key == "Price")
                        itemStruct.price = value;
                    else if (key == "Number of jewels")
                        itemStruct.numberOfJewels = value;
                    else if (key == "Dial")
                        itemStruct.dial = value;

                }
            }
        }

        // Recursively process child nodes
        extractValues(curNode->children, itemStruct);
    }
}