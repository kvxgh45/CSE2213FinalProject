#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Order.h"
#include "Shirts.h"
#include "shoppingCart.h"
#include "account.h"
#include "user.h"


using namespace std;

struct Account {
    //string name;
    string username;
    string password;
};

bool createAccount(Account& account) {
    cout << "Create an Account" << endl;

     cin.ignore(); 
    
    //cout << "Name: ";
    //getline(cin, account.name);

    cout << "Username: ";
    getline(cin, account.username);

    cout << "Password: ";
    getline(cin, account.password);

    cout << "Account created successfully!" << endl << endl;
    return true;
}

bool login(Account& account) {
    string name, username, password;

    cout << "Login" << endl;
    cout << "Username: ";
    getline(cin, username);

    cout << "Password: ";
    getline(cin, password);

    if (username == account.username && password == account.password) {
        cout << "Login successful! Welcome, " << name << "!" << endl;
        return true;
    }
    else {
        cout << "Login failed. Please try again." << endl;
        return false;
    }
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. View items" << endl;
    cout << "2. View Cart" << endl;
    cout << "3. View Account" << endl;
    cout << "4. Logout" << endl;
}

void viewItems(vector<Shirts>& shirts) {
    cout << "Viewing items..." << endl << "-------------------" << endl;
    for (int i = 0; i < shirts.size(); i++)
    {
        cout << i + 1 << ") " << shirts[i].getBrand() << " " << shirts[i].getStyle() << " | Size: " <<
            shirts[i].getSize() << " Color: " << shirts[i].getColor() << " Fabric: " << shirts[i].getFabric() <<
            endl << "Price: " << shirts[i].getPrice() << "# in Stock: " << shirts[i].getQuantity() << endl;
        cout << endl;

        /*cout << "ShirtID: " << shirts[i].getShirtID() << endl;
        cout << "Brand: " << shirts[i].getBrand() << endl;
        cout << "Style: " << shirts[i].getStyle() << endl;
        cout << "Size: " << shirts[i].getSize() << endl;
        cout << "Color: " << shirts[i].getColor() << endl;
        cout << "Fabric: " << shirts[i].getFabric() << endl;
        cout << "Quanity: " << shirts[i].getQuantity() << endl;
        cout << "Price: " << shirts[i].getPrice() << endl;*/
        cout << endl;

         }
         
    while (true) {
        cout << "Enter the item number to add to cart (or 0 to go back to the main menu): ";
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= shirts.size()) {
            cart.addItem(shirts[choice - 1]);
            cout << "Item added to cart." << endl;
            break; // Exit the loop and return to the main menu
        }
        else if (choice == 0) {
            // Go back to the main menu
            return;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
}

void viewCart() {
    cout << "Viewing cart..." << endl;
}

void viewAccount() {
    cout << "Viewing account..." << endl;
}

void displayOrder(vector<Order>& order) {
    cout << "Viewing order history..." << endl << "-------------------" << endl;
    for (int i = 0; i < order.size(); i++) {

        cout << "OrderID: " << order[i].getOrderID() << endl;
        cout << "Items: " << order[i].getItems() << endl;
        cout << "Cost: " << order[i].getCost() << endl;
        cout << "Quantity: " << order[i].getQuantity() << endl;
        cout << "Shipping: " << order[i].getShipping() << endl;
        cout << endl;
    }
}

void editShirts(vector<Shirts>& shirts);
//void editUsers(vector<Users>& user);
//void editAccount(vector<Account>& account);

void addOrder(vector<Order>& order);

void readShirts(vector<Shirts>& shirts) {
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
//void readUsers(vector<Users>& user);
//void readAccount(vector<Account>& account);
void readOrder(vector<Order>& order);

int main() {
    Account userAccount;
    bool loggedIn = false;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Create an account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            createAccount(userAccount);
            break;
        case 2:
            loggedIn = login(userAccount);
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

    // Create an instance of ShoppingCart
    ShoppingCart cart;

    // Main program loop
    vector<Shirts> shirts;
    //readShirts(shirts);

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            viewItems(shirts);
            break;
        case 2:
             cart.displayCart();
            break;
        case 3:
            viewAccount();
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
