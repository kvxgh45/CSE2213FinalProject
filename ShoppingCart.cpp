#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
}

// getters
string ShoppingCart::getItemName() { return ItemName; };
string ShoppingCart::getQuantity() { return Quantity; };
string ShoppingCart::getPrice() { return Price; };
string ShoppingCart::getShipping() { return Shipping; };
string ShoppingCart::getBilling() { return Billing; };
string ShoppingCart::getPayment() { return Payment; };


// setters
void ShoppingCart::setItemName(string ItemName) { this->Quantity = ItemName; };
void ShoppingCart::setQuantity(string Quantity) { this->Quantity = Quantity; };
void ShoppingCart::setPrice(string Price) { this->Quantity = Price; };
void ShoppingCart::setShipping(string Shipping) { this->Quantity = Shipping; };
void ShoppingCart::setBilling(string Billing) { this->Quantity = Billing; };
void ShoppingCart::setPayment(string Paymetn) { this->Payment = Payment; };
