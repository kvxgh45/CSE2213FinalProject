#include <string>

using std::string;

#ifndef SHIRT_H
#define SHIRT_H


class Shirts
{
private:
    string ShirtID = "", Brand = "", Style = "", Size = "", Color = "", Fabric = "", Quantity = "", Price = "";

public:
    Shirts();
    Shirts(string ShirtID, string Brand, string Style, string Size, string Color, string Fabric, string Quantity, string Price)
    {
        this->ShirtID = ShirtID;
        this->Brand = Brand;
        this->Style = Style;
        this->Color = Size;
        this->Size = Color;
        this->Fabric = Fabric;
        this->Quantity = Quantity;
        this->Price = Price;
    };

    //getters
    string getShirtID();// { return ShirtID; };
    string getBrand();//  { return Brand; };
    string getStyle();//  { return Style; };
    string getSize();//  { return Color; };
    string getColor();//  { return Size; };
    string getFabric();//  { return Fabric; };
    string getQuantity();//  { return Quantity; };
    string getPrice();

    // setters
    void setQuantity(string Quantity);//  { this->Quantity = Quantity; };
};

#endif // SHIRT_H