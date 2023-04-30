#include <string>

using std::string;

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H


class ShoppingCart
{
private:
    string ItemName = "", Quantity = "", Price = "", Shipping = "", Billing = "", Payment="";

public:
    ShoppingCart();
    ShoppingCart(string ItemName, string Quantity, string Price, string Shipping, string Billing, string Payment)
    {
        this->ItemName = ItemName;
        this->Quantity = Quantity;
        this->Price = Price;
        this->Shipping = Shipping;
        this->Billing = Billing;
        this->Payment = Payment;
    };

    // getters
    string getItemName();
    string getQuantity();
    string getPrice();
    string getShipping();
    string getBilling();
    string getPayment();

    // setters
    void setItemName(string ItemName);
    void setQuantity(string Quantity);
    void setPrice(string Price);
    void setShipping(string Shipping);
    void setBilling(string Billing);
    void setPayment(string Payment);
};

#endif // SHOPPINGCART_H
