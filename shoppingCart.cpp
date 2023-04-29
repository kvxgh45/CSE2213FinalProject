#include "ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart() {
    item = "";
    quantity = 0;
    price = 0.0;
    shipping = "";
    billing = "";
    payment = 0;
}

std::string ShoppingCart::getItemName() {
    return item;
}

int ShoppingCart::getQuantity() {
    return quantity;
}

double ShoppingCart::getPrice() {
    return price;
}

void ShoppingCart::addItem(std::string name) {
    item = name;
    // Add implementation to update quantity and price accordingly
    quantity++;
    // Update the price based on the added item (e.g., retrieve price from a database or calculation)
    price += 10.0;
}

void ShoppingCart::removeItem(std::string name) {
    // Add implementation to remove the specified item from the cart
    if (item == name && quantity > 0) {
        quantity--;
        // Update the price based on the removed item (e.g., retrieve price from a database or calculation)
        price -= 10.0;
    }
}

void ShoppingCart::setQuantity(int quantity) {
    this->quantity = quantity;
}

void ShoppingCart::displayCart() {
    std::cout << "Item: " << item << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Price: $" << price << std::endl;
}

std::string ShoppingCart::getShipping() {
    return shipping;
}

void ShoppingCart::setTmpShipping(std::string address) {
    shipping = address;
}

std::string ShoppingCart::getBilling() {
    return billing;
}

void ShoppingCart::setTmpBilling(std::string address) {
    billing = address;
}

int ShoppingCart::getPayment() {
    return payment;
}

void ShoppingCart::setTmpPayment(int card) {
    payment = card;
}

void ShoppingCart::purchase() {
    // Add implementation to process the purchase and finalize the transaction
    std::cout << "Purchase complete!" << std::endl;
}
