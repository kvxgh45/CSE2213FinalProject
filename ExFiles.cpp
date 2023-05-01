#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Order.h"
#include "Book.h"
#include "ShoppingCart.h"
#include "account.h"
#include "user.h"

using namespace std;

//void displayShirts(vector<Shirts>& shirts);
void readShirts(vector<Shirts>& shirts);
string createID();
void displayOrder(vector<Order>& order);
void createUser(vector<User>& user) {

    ofstream outfile;
    outfile.open("User.txt");

    cout << "Enter your accont information" << endl;
    string name, username, password;

    cout << "Name: ";
    cin >> name;

    cout << "Username: ";
    cin >> username;


    cout << "Password: ";
    cin >> password;

    User tmp(name, username, password);
    user.push_back(tmp);

    outfile << user[0].getName() << endl;
    outfile << user[0].getUsername() << endl;
    outfile << user[0].getPassword() << endl;
    outfile << endl;

    outfile.close();
}
void createAccount(vector<Account>& account) {

    ofstream outfile;
    outfile.open("Account.txt");

    cout << endl;
    string shipping, billing, card;

    cout << "Shipping address: ";
    cin >> shipping;

    cout << "Billing address: ";
    cin >> billing;

    cout << "Credit card information: ";
    cin >> card;
    cout << endl;

    Account tmp(shipping, billing, card);
    account.push_back(tmp);

    outfile << account[0].getShipping() << endl;
    outfile << account[0].getBilling() << endl;
    outfile << account[0].getPayment() << endl;
    outfile << endl;

    outfile.close();

    cout << "Account created!" << endl << endl;
}
bool login(vector<User>& user) {

    string name, username, password;

    cout << "Login" << endl;
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;
    cout << endl;

    if (username == user[0].getUsername() && password == user[0].getPassword()) {
        cout << "Login successful! Welcome, " << user[0].getName() << "!" << endl << endl;
        return true;
    }
    else {
        cout << "Login failed. Please try again." << endl;
        return false;
    }
}
void displayMenu();
void displayCartMenu();
void viewCart(vector<ShoppingCart>& cart) {

    cout << "Here is your current shopping cart: " << endl << endl;

    for (int i = 0; i < cart.size(); i++) {

        cout << i + 1 << ") ----------" << endl;
        cout << "Shirt Name: " << cart[i].getItemName() << " - Quantity: " << cart[i].getQuantity() << endl;
        cout << "Price: $" << stod(cart[i].getPrice()) * stod(cart[i].getQuantity()) << endl << endl;
    }

    cout << "Shipping address: " << cart[0].getShipping() << endl;
    cout << "Billing address: " << cart[0].getBilling() << endl;
    cout << "Credit card information: " << cart[0].getPayment() << endl << endl;



}
void viewAccount();
void viewItems(vector<Shirts>& shirts);

void editShirts(vector<Shirts>& shirts);
void editUsers(vector<User>& user);
void editAccount(vector<Account>& account);
void tmpAddress(vector<ShoppingCart>& cart) {

    string tmpShipping;
    string tmpBilling;

    cout << endl << "Enter your temporary shipping address: ";
    getline(cin, tmpShipping);

    cout << endl << "Enter your temporary billing address: ";
    getline(cin, tmpBilling);

    cart[0].setShipping(tmpShipping);
    cart[0].setBilling(tmpBilling);

    cout << endl << endl << "Addresses changed!" << endl << endl;


}
void tmpCard(vector<ShoppingCart>& cart) {

    string tmpCard;

    cout << endl << "Enter your temporary credit card number: ";
    cin >> tmpCard;

    cart[0].setPayment(tmpCard);

    cout << endl << endl << "Payment info changed !" << endl << endl;
}
void purchase(vector<Shirts>& shirts, vector<ShoppingCart>& cart, vector<Order>& order) {

    //Calculating total cost and outputting to user
    double totalCost = 0;

    for (int i = 0; i < cart.size(); i++) {

        totalCost += round(stod(cart[i].getPrice()) * stod(cart[i].getQuantity()));
    }

    cout << "Payment complete!" << endl << "Your total is: $" << totalCost << endl << endl;

    //Writing cart information into the order.txt file
    string ID = "ORD-" + createID();
    string orderList;
    string quantityList;

    for (int i = 0; i < cart.size(); i++) {

        orderList += cart[i].getItemName() + ", ";
    }

    for (int i = 0; i < cart.size(); i++) {

        quantityList += cart[i].getQuantity() + ", ";
    }

    Order newOrder(ID,orderList, to_string(totalCost), quantityList, cart[0].getShipping());
    order.push_back(newOrder);

    ofstream outfile;
    outfile.open("Order.txt");

    outfile << order[0].getOrderID() << endl;
    outfile << order[0].getItems() << endl;
    outfile << order[0].getCost() << endl;
    outfile << order[0].getQuantity() << endl;
    outfile << order[0].getShipping() << endl;
    outfile << endl;

    outfile.close();

    //Updating quantity of shirts in ShirtInventory.txt file
    for (int i = 0; i < shirts.size(); i++) {
        for (int j = 0; i < cart.size(); i++) {

            if (cart[j].getPrice() == shirts[i].getPrice()) {

                int newQuantity = stoi(shirts[i].getQuantity()) - stoi(cart[j].getQuantity());
                shirts[i].setQuantity(to_string(newQuantity));
            }
        }
    }

    editShirts(shirts);

    //Clearing the contents of the shopping cart
    cart.clear();


}

void addOrder(vector<Order>& order);
void addShirt(vector<Shirts>& shirts, vector<ShoppingCart>& cart, vector<Account>& account) {

    int shirtNum;
    int shirtQuantity=1;
    bool selection = false;
    bool selection2 = false;

    while (selection == false) {

        cout << "Enter the number of the shirt you wish to buy (1-10): ";
        cin >> shirtNum;

        if (shirtNum >= 1 && shirtNum < 11) {
            selection = true;
        }

        else {

            cout << "Invalid selction." << endl;
        }

    }

    while (selection2 == false) {

        cout << "How many of this item do you wish to buy?: ";
        cin >> shirtQuantity;

        if (shirtQuantity > 0) {

            selection2 = true;
        }

        else {
            cout << "Invalid number." << endl;
        }

    }

    int i = shirtNum - 1;
    string itemName = shirts[i].getBrand() + " " + shirts[i].getStyle();
    string Quantity = to_string(shirtQuantity);
    string price = shirts[i].getPrice();
    string shipping = account[0].getShipping();
    string billing = account[0].getBilling();
    string payment = account[0].getPayment();

    ShoppingCart tmp(itemName, Quantity, price, shipping, billing, payment);
    cart.push_back(tmp);

    cout << endl << itemName << " added to cart!" << endl << endl;






}
void removeShirt(vector<ShoppingCart>& cart) {

    int numItem;

    if (cart.empty()) {

        cout << "Your cart is currently empty." << endl << endl;
    }

    else {

        bool sel = false;

        viewCart(cart);
        cout << endl << endl;
        
        while (sel == false) {

            cout << "Please select the shirt number that you wish to remove: ";
            cin >> numItem;

            if (numItem >= 1 && numItem <= cart.size()) {
                sel = true;
            }

            else {
                cout << "Invalid selection." << endl;
            }

        }

        cout << endl << endl;

        cart.erase(cart.begin()+(numItem-1));

        cout << "Shirt removed!" << endl << endl;
        
    }
}


void readUsers(vector<User>& user);
void readAccount(vector<Account>& account);
void readOrder(vector<Order>& order);


int main() {

    vector<User> user;
    vector<Account> account;
    vector<Order> order;
    vector<Shirts> shirts;
    vector<ShoppingCart> cart;

    bool loggedIn = false;

    while (true) {
        cout << "Start Menu:" << endl;
        cout << "1. Create an account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            createUser(user);
            createAccount(account);
            break;
        case 2:
            readUsers(user);
            loggedIn = login(user);
            break;
        case 3:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        if (loggedIn) {
            break;
        }
    }

    // Main program loop

    readShirts(shirts);
    addShirt(shirts, cart, account);
    viewCart(cart);
    addShirt(shirts, cart, account);
    addShirt(shirts, cart, account);
    viewCart(cart);
    removeShirt(cart);
    viewCart(cart);
    purchase(shirts, cart, order);



    while (true) {
        displayMenu();
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            viewItems(shirts);
            break;
        case 2:
            while (true) {
                displayCartMenu();
                cout << "Enter your choice: ";
                    int choice2;
                    cin >> choice2;

                    //more swithches?


            }
            break;
        case 3:
            //viewAccount(account);
            break;
        case 4:
            cout << "Logging out..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }


    return 0;
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. View items" << endl;
    cout << "2. Purchase Shirts" << endl;
    cout << "3. View Account" << endl;
    cout << "4. Logout" << endl;
}

void displayCartMenu() {

    cout << "Shopping Cart:" << endl;
    cout << "1. View items" << endl;
    cout << "2. View cart" << endl;
    cout << "3. Add shirt" << endl;
    cout << "4. Remove shirt" << endl;
    cout << "5. Enter temporary shipping/billing address" << endl;
    cout << "6. Enter temporary payment information" << endl;
    cout << "7. Purchase shirts" << endl;
    cout << "8. Logout" << endl;
}

void displayAccountMenu() {

    cout << "Account:" << endl;
    cout << "1. Shipping/Billing addresses" << endl;
    cout << "2. Credit cart information" << endl;
    cout << "3. View Order History" << endl;
    cout << "4. Change addresses" << endl;
    cout << "5. Change credit card" << endl;
    cout << "6. Delete account" << endl;
}

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
        outfile << shirts[i].getPrice() << endl;
        outfile << endl;
    }

    outfile.close();

}

void editUsers(vector<User>& user) {
    ofstream outfile;
    outfile.open("User.txt");
    for (int i = 0; i < user.size(); i++)
    {
        outfile << user[i].getName() << endl;
        outfile << user[i].getUsername() << endl;
        outfile << user[i].getPassword() << endl;
        outfile << endl;
    }
    outfile.close();
}

void editAccount(vector<Account>& account) {
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
}

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

void readShirts(vector<Shirts>& shirts)
{
    ifstream infile;
    infile.open("ShirtsInventory.txt");

    string line;

    while (getline(infile, line))
    {
        string brand, style, size, sID, color, fabric, quantity, price;

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
        price = line;

        getline(infile, line);

        Shirts temp(sID, brand, style, size, color, fabric, quantity, price);

        shirts.push_back(temp);
    }

    infile.close();
}

void readUsers(vector<User>& user)
{
    ifstream infile;
    infile.open("User.txt");
    string line;
    while (getline(infile, line))
    {
        string uName, name, password;
        name = line;

        getline(infile, line);
        uName = line;

        getline(infile, line);
        password = line;

        getline(infile, line);

        User temp(name, uName, password);
        user.push_back(temp);
    }
    infile.close();
}

void readAccount(vector<Account>& account) {
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

        Account temp(shipping, billing, payment);
        account.push_back(temp);
    }
    infile.close();
}

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

void viewItems(vector<Shirts>& shirts) {
    cout << "Viewing items..." << endl << "-------------------" << endl;
    for (int i = 0; i < shirts.size(); i++)
    {
        cout << i + 1 << ") " << shirts[i].getBrand() << " " << shirts[i].getStyle() << " | Size: " <<
            shirts[i].getSize() << " Color: " << shirts[i].getColor() << " Fabric: " << shirts[i].getFabric() <<
            endl << "Price: $" << shirts[i].getPrice() << " # in Stock: " << shirts[i].getQuantity() << endl;
        cout << endl;

        cout << endl;
    }
}

string createID() {

    srand((unsigned)time(nullptr));
    string ID;

    for (int i = 0; i < 10; i++) {

        ID += to_string(rand() % 10);
    }

    return ID;
}