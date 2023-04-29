#include <iostream>
#include <string>
#include<vector>
#include "account.h";

using namespace std;
Account::Account() {
}
// Getters 
string Account::getShipping() {
    return Shipping;
}
string Account::getBilling() {
    return Billing;
}

string Account::getOrderInfo() {
    return Billing;
}
string Account::getPayment() {
    return Payment;
}
string Account::setShipping(string address1) {
    this->Shipping = Shipping;
}
string Account::setBilling(string address2) {
    this->Billing = Billing;

}
string Account::setPayment(string card) {
    this->Payment = Payment;
}
