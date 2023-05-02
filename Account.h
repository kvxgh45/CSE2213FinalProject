#include <string>

using std::string;

#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
private:
    string Shipping = "", Billing = "", Payment = "";

public:
    Account();
    Account(string Shipping, string Billing, string Payment)
    {
        this->Shipping = Shipping;
        this->Billing = Billing;
        this->Payment = Payment;
    };

    // getters
    string getBilling();
    string getShipping();
    string getPayment();
    void setShipping(string shipping);
    void setBilling(string billing);
    void setPayment(string Payment);

};

#endif // USER_H