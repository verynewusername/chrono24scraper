#include "main.ih"

void run()
{
    Crawler crawler;

    std::ofstream ofs("output.csv", std::ofstream::out);

    // Add the top row of the CSV file
    ofs << "Listing Code,Brand,Model,Reference Number,Movement,Case Material,Bracelet Material,Condition,Year of Production,Scope Of Delivery,Gender,Price,Number of Jewels,Dial,URL\n";

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

    ofs.close();
    
}
