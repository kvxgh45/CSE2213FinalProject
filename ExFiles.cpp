#include <iostream>
#include <fstream>
#include <vector>
#include "Book.h"
#include "Order.h"

using namespace std;

void displayShirts(vector<Shirts>& shirts);
void displayOrder(vector<Order>& order);

void editShirts(vector<Shirts>& shirts);
//void editUsers(vector<Users>& user);
//void editAccount(vector<Account>& account);

void addOrder(vector<Order>& order);

void readShirts(vector<Shirts>& shirts);
//void readUsers(vector<Users>& user);
//void readAccount(vector<Account>& account);
void readOrder(vector<Order>& order);

int main()
{
    vector<Shirts> shirts;
    vector<Order> orderHis;

    //readShirts(shirts);
    //displayShirts(shirts);
    //editShirts(shirts);

    
    Order tmp("correctversion?", "Ralph T-shirt", "89.99", "5", "Lake Estates");
    //
    //
    readOrder(orderHis);
    orderHis.push_back(tmp);
    addOrder(orderHis);
    displayOrder(orderHis);
    cout << endl;

    return 0;
}

//Rudimentary displays
void displayShirts(vector<Shirts>& shirts)
{
    for (int i = 0; i < shirts.size(); i++)
    {
        cout << "ShirtID: " << shirts[i].getShirtID() << endl;
        cout << "Brand: " << shirts[i].getBrand() << endl;
        cout << "Style: " << shirts[i].getStyle() << endl;
        cout << "Size: " << shirts[i].getSize() << endl;
        cout << "Color: " << shirts[i].getColor() << endl;
        cout << "Fabric: " << shirts[i].getFabric() << endl;
        cout << "Quanity: " << shirts[i].getQuantity() << endl;
        cout << endl;
    }
}

void displayOrder(vector<Order>& order) {

    for (int i = 0; i < order.size(); i++) {

        cout << "OrderID: " << order[i].getOrderID() << endl;
        cout << "Items: " << order[i].getItems() << endl;
        cout << "Cost: " << order[i].getCost() << endl;
        cout << "Quantity: " << order[i].getQuantity() << endl;
        cout << "Shipping: " << order[i].getShipping() << endl;
        cout << endl;
    }
}



//Edits (or removes) shirts from the txt file (should only be # in stock)
void editShirts(vector<Shirts>& shirts) {

    ofstream outfile;
    outfile.open("ShirtsInventory.txt");

    for (int i = 0; i < shirts.size(); i++)
    {
        outfile << shirts[i].getShirtID() << endl;
        outfile << shirts[i].getBrand() << endl;
        outfile << shirts[i].getStyle() << endl;
        outfile << shirts[i].getSize() << endl;
        outfile << shirts[i].getColor() << endl;
        outfile << shirts[i].getFabric() << endl;
        outfile << shirts[i].getQuantity() << endl;
        outfile << endl;
    }

    outfile.close();

}

/*void editUsers(vector<Users>& user) {

    ofstream outfile;
    outfile.open("User.txt");

    for (int i = 0; i < user.size(); i++)
    {
        outfile << user[i].getName() << endl;
        outfile << user[i].getUsername() << endl;
        outfile << user[i].getPassword() << endl;
        outfile << user[i].getEmail() << endl;
        outfile << endl;
    }

    outfile.close();

}*/


/*void editAccount(vector<Account>& account) {

    ofstream outfile;
    outfile.open("Account.txt");

    for (int i = 0; i < account.size(); i++)
    {
        outfile << account[i].getShipping() << endl;
        outfile << account[i].getBilling() << endl;
        outfile << account[i].getPayment() << endl;
        outfile << endl;
    }

    outfile.close();
}*/

void addOrder(vector<Order>& order) {

    ofstream outfile;
    outfile.open("Order.txt", ios::app);

    outfile << order[0].getOrderID() << endl;
    outfile << order[0].getItems() << endl;
    outfile << order[0].getCost() << endl;
    outfile << order[0].getQuantity() << endl;
    outfile << order[0].getShipping() << endl;
    outfile << endl;

    outfile.close();

}

//Reads ShirtsInventory.txt to put into the vector
void readShirts(vector<Shirts>& shirts)
{
    ifstream infile;
    infile.open("ShirtsInventory.txt");

    string line;

    while (getline(infile, line))
    {
        string brand, style, size, sID, color, fabric, quantity;

        sID = line;

        getline(infile, line);
        brand = line;

        getline(infile, line);
        style = line;

        getline(infile, line);
        size = line;

        getline(infile, line);
        color = line;

        getline(infile, line);
        fabric = line;

        getline(infile, line);
        quantity = line;

        getline(infile, line);

        Shirts temp(sID, brand, style, size, color, fabric, quantity);

        shirts.push_back(temp);
    }

    infile.close();
}

/*void readUsers(vector<Users>& user)
{
    ifstream infile;
    infile.open("User.txt");

    string line;

    while (getline(infile, line))
    {
        string uName, email, fName, password;

        fName = line;

        getline(infile, line);
        uName = line;

        getline(infile, line);
        email = line;

        getline(infile, line);
        password = line;

        getline(infile, line);

        Users temp(fName, uName, email, password);

        user.push_back(temp);
    }

    infile.close();
}*/

/*void readAccount(vector<Account>& account) {

    ifstream infile;
    infile.open("Account.txt");

    string line;

    while (getline(infile, line))
    {
        string shipping, billing, payment;

        payment = line;

        getline(infile, line);
        shipping = line;

        getline(infile, line);
        billing = line;

        getline(infile, line);

        Account temp(payment, shipping, billing);

        account.push_back(temp);
    }

    infile.close();
}*/

void readOrder(vector<Order>& order) {

    ifstream infile;
    infile.open("Order.txt");

    string line;

    while (getline(infile, line))
    {
        string items, cost, quantity, orderID, shipping;

        orderID = line;

        getline(infile, line);
        items = line;

        getline(infile, line);
        cost = line;

        getline(infile, line);
        quantity = line;

        getline(infile, line);
        shipping = line;

        getline(infile, line);

        Order temp(orderID, items, cost, quantity, shipping);

        order.push_back(temp);
    }

    infile.close();
}
