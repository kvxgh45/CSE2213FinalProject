#include <iostream>
#include <string>
#include<vector>
#include "Account.h"

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

/*string Account::getOrderInfo() {
    return Billing;
}*/

string Account::getPayment() {
    return Payment;
}
void Account::setShipping(string address1) {
    this->Shipping = Shipping;
}
void Account::setBilling(string address2) {
    this->Billing = Billing;

}
void Account::setPayment(string card) {
    this->Payment = Payment;
}