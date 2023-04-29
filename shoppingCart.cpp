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
    
    // Ask the user if they would like to remove an item from the cart
    char choice;
    std::cout << "Would you like to remove an item from the cart? (r/n): ";
    std::cin >> choice;
    
    if (choice == 'r' || choice == 'R') {
        std::string itemName;
        std::cout << "Enter the name of the item to remove: ";
        std::cin >> itemName;
        removeItem(itemName);
    }

     // Calculate and display the total price
    double totalPrice = quantity * price;
    std::cout << "Total Price: $" << totalPrice << std::endl;
    
    // Ask the user if they would like to proceed to checkout
    std::cout << "Would you like to proceed to checkout? (y/n): ";
    std::cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        purchase();
    }
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
    // Check if the shopping cart is empty
    if (item.empty() || quantity == 0 || price == 0.0) {
        std::cout << "Shopping cart is empty. Cannot proceed with the purchase." << std::endl;
        return;
    }
    
    // Check if the shipping and billing addresses are set
    if (shipping.empty() || billing.empty()) {
        std::cout << "Shipping or billing address is missing. Cannot proceed with the purchase." << std::endl;
        return;
    }
    
    // Check if the payment information is set
    if (payment == 0) {
        std::cout << "Payment information is missing. Cannot proceed with the purchase." << std::endl;
        return;
    }
    
    // Proceed to checkout
    std::cout << "Checkout successful! Thank you for your purchase." << std::endl;
    
    // Reset the shopping cart
    item = "";
    quantity = 0;
    price = 0.0;
    shipping = "";
    billing = "";
    payment = 0;
}
