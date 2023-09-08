#include "main.ih"

void run()
{
    Crawler crawler;

    std::ofstream ofs("output.csv", std::ofstream::out);

    while (crawler.getNextContent())
    {
        ItemStruct temp = crawler.getItemBuffer();

        ofs << temp.listingCode << ','
            << temp.brand << ','
            << temp.model << ','
            << temp.referenceNumber << ','
            << temp.movement << ','
            << temp.caseMaterial << ','
            << temp.braceletMaterial << ','
            << temp.condition << ','
            << temp.yearOfProduction << ','
            << temp.scopeOfDelivery << ','
            << temp.gender << ','
            << temp.price << ','
            << temp.numberOfJewels << ','
            << temp.dial << ','
            << temp.url << '\n';
    }
    
}
