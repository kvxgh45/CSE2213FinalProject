#include <string>

using std::string;

#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
private:
    string Shipping = "", Billing = "", OrderInfo = "", Payment = "";

public:
    Account();
    Account(string Shipping, string Billing, string OrderInfo, string Payment)
    {
        this->Shipping = Shipping;
        this->Billing = Billing;
        this->OrderInfo = OrderInfo;
        this->Payment = Payment;
    };

    // getters
    string getBilling();
    string getOrderInfo();
    string getShipping();
    string getPayment();
    string setShipping(string shipping);
    string setBilling(string billing);
    string setPayment(string Payment);

};

#endif // USER_H
