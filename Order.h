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
    string getOrderID();// { return OrderID; };
    string getItems();// { return Items; };
    string getCost();// { return Cost; };
    string getShipping();// { return Shipping; };
    string getQuantity();// { return Quantity; };

    // setters
    void setOrderID(string OrderID);// { this->Quantity = OrderID; };
    void setItems(string Items);// { this->Quantity = Items; };
    void setCost(string Cost);// { this->Quantity = Cost; };
    void setShipping(string Shipping);// { this->Quantity = Shipping; };
    void setQuantity(string Quantity);// { this->Quantity = Quantity; };
};

#endif // ORDER_H