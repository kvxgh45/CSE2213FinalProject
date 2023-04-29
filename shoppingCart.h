#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>

class ShoppingCart {
private:
    std::string item;
    int quantity;
    double price;
    std::string shipping;
    std::string billing;
    int payment;

public:
    ShoppingCart();
    std::string getItemName();
    int getQuantity();
    double getPrice();
    void addItem(std::string name);
    void removeItem(std::string name);
    void setQuantity(int quantity);
    void displayCart();
    std::string getShipping();
    void setTmpShipping(std::string address);
    std::string getBilling();
    void setTmpBilling(std::string address);
    int getPayment();
    void setTmpPayment(int card);
    void purchase();
};

#endif // SHOPPINGCART_H
