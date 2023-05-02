#include <string>

using std::string;

#ifndef ORDER_H
#define ORDER_H


class Order
{
private:
    string OrderID = "", Items = "", Cost = "", Shipping = "", Quantity = "";

public:
    Order();
    Order(string OrderID, string Items, string Cost, string Quantity, string Shipping)
    {
        this->OrderID = OrderID;
        this->Items = Items;
        this->Cost = Cost;
        this->Quantity = Quantity;
        this->Shipping = Shipping;
    };

    // getters
    string getOrderID();
    string getItems();
    string getCost();
    string getShipping();
    string getQuantity();

    // setters
    void setOrderID(string OrderID);
    void setItems(string Items);
    void setCost(string Cost);
    void setShipping(string Shipping);
    void setQuantity(string Quantity);
};

#endif // ORDER_H