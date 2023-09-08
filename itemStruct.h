#ifndef ITEMSTRUCT_H
#define ITEMSTRUCT_H

#include <string>           // std::string

struct ItemStruct
{
    // Basic Info
    std::string listingCode;
    std::string brand;
    std::string model;
    std::string referenceNumber;
    std::string movement;
    std::string caseMaterial;
    std::string braceletMaterial;
    std::string condition;
    std::string yearOfProduction;
    std::string scopeOfDelivery;
    std::string gender;
    std::string price;

    // Caliber
    std::string numberOfJewels;

    // Case
    std::string dial;

    // URL
    std::string url;
};

#endif // Path: itemStruct.h
