#include "Scraper.h"

void Scraper::extractValues(xmlNode* node, ItemStruct* itemStruct) {
    for (xmlNode* curNode = node; curNode; curNode = curNode->next) {
        if (curNode->type == XML_ELEMENT_NODE && xmlStrcmp(curNode->name, reinterpret_cast<const xmlChar*>("tr")) == 0) {
            // Check if this is a <tr> element

            // Initialize variables to store the key and value
            std::string key;
            std::string value;

            // Iterate through child nodes of the <tr> element
            for (xmlNode* childNode = curNode->children; childNode; childNode = childNode->next) {
                if (childNode->type == XML_ELEMENT_NODE && xmlStrcmp(childNode->name, reinterpret_cast<const xmlChar*>("td")) == 0) {
                    // Check if this is a <td> element
                    xmlChar* classAttr = xmlGetProp(childNode, reinterpret_cast<const xmlChar*>("class"));
                    if (classAttr && xmlStrcmp(classAttr, reinterpret_cast<const xmlChar*>("p-r-2")) == 0) {
                        // This <td> element has class "p-r-2"
                        xmlNode* strongNode = childNode->children;
                        if (strongNode && xmlStrcmp(strongNode->name, reinterpret_cast<const xmlChar*>("strong")) == 0) {
                            // The content of the <strong> tag is the key
                            key = reinterpret_cast<const char*>(xmlNodeGetContent(strongNode));
                        }
                    } else {
                        // This <td> element does not have class "p-r-2"
                        // The content of this <td> tag is the value
                        value = reinterpret_cast<const char*>(xmlNodeGetContent(childNode));
                    }
                }
            }

            // Check if both key and value are not empty
            if (!key.empty() && !value.empty()) {

                // delete newlines in value
                value.erase(std::remove(value.begin(), value.end(), '\n'), value.end());

                // Store the key-value pair in the itemStruct
                if (key == "Listing code")
                    itemStruct->listingCode = value;
                else if (key == "Brand")
                    itemStruct->brand = value;
                else if (key == "Model")
                    itemStruct->model = value;
                else if (key == "Reference number")
                    itemStruct->referenceNumber = value;
                else if (key == "Movement")
                    itemStruct->movement = value;
                else if (key == "Case material")
                    itemStruct->caseMaterial = value;
                else if (key == "Bracelet material")
                    itemStruct->braceletMaterial = value;
                else if (key == "Condition")
                    itemStruct->condition = value;
                else if (key == "Year of production")
                    itemStruct->yearOfProduction = value;
                else if (key == "Scope of delivery")
                    itemStruct->scopeOfDelivery = value;
                else if (key == "Gender")
                    itemStruct->gender = value;
                else if (key == "Price")
                    itemStruct->price = value;
                else if (key == "Number of jewels")
                    itemStruct->numberOfJewels = value;
                else if (key == "Dial")
                    itemStruct->dial = value;
            }
        }

        // Recursively process child nodes
        extractValues(curNode->children, itemStruct);
    }
}
