#include <string>

using std::string;

#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
    private:
        string Shipping = "", Billing = "", OrderInfo = "",Payment = ""; 
     
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
        string setShipping(string shipping,address1);
        string setBilling(string billing, address2);
        string setPayment(string Payment, card);

        // setters
        void deleteAccount(); 
};

#endif // USER_H