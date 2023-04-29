#include "Order.h"

Order::Order()
{
}

// getters
string Order::getOrderID() { return OrderID; };
string Order::getItems() { return Items; };
string Order::getCost() { return Cost; };
string Order::getShipping() { return Shipping; };
string Order::getQuantity() { return Quantity; };

// setters
void Order::setOrderID(string OrderID) { this->Quantity = OrderID; };
void Order::setItems(string Items) { this->Quantity = Items; };
void Order::setCost(string Cost) { this->Quantity = Cost; };
void Order::setShipping(string Shipping) { this->Quantity = Shipping; };
void Order::setQuantity(string Quantity) { this->Quantity = Quantity; };