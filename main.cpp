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

//void displayShirts(vector<Shirts>& shirts);
void displayOrder(vector<Order>& order);
void createUser(vector<User>& user) {

    ofstream outfile;
    outfile.open("User.txt");

    cout << "Creating your Account" << endl << endl;
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


}
void createAccount(vector<Account>& account) {

    ofstream outfile;
    outfile.open("Account.txt");

    cout << "Creating your Account" << endl << endl;
    string shipping, billing, card;

    cout << "Please enter your shipping address: ";
    cin >> shipping;
    cout << endl;

    cout << "Please enter your billing address: ";
    cin >> billing;
    cout << endl;

    cout << "Please enter your credit card information: ";
    cin >> card;
    cout << endl;

    Account tmp(shipping, billing, card);
    account.push_back(tmp);

    outfile << account[0].getShipping() << endl;
    outfile << account[0].getBilling() << endl;
    outfile << account[0].getPayment() << endl;
    outfile << endl;
}
bool login(vector<User>& user) {

    string name, username, password;

    cout << "Login" << endl;
    cout << "Username: ";
    cin >> username;
    cout << endl;

    cout << "Password: ";
    cin >> password;

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
void displayCartMunu();
void viewCart(vector<ShoppingCart>& cart) {

    cout << "Here is your current shopping cart: " << endl << endl;

    for (int i = 0; i < cart.size(); i++) {

        cout << i + 1 << ") ----------" << endl;
        cout << "Shirt Name: " << cart[i].getItemName() << " - Quantity: " << cart[i].getQuantity() << endl;
        cout << "Price: $" << stoi(cart[i].getPrice()) * stoi(cart[i].getQuantity()) << endl << endl;
    }

    cout << "Shipping address: " << cart[0].getShipping() << endl;
    cout << "Billing address: " << cart[0].getBilling() << endl;
    cout << "Credit card information: " << cart[0].getPayment() << endl;



}
void viewAccount();
void viewItems(vector<Shirts>& shirts);

void editShirts(vector<Shirts>& shirts);
void editUsers(vector<User>& user);
void editAccount(vector<Account>& account);

void addOrder(vector<Order>& order);
void addShirt(vector<Shirts>& shirts, vector<ShoppingCart>& cart, vector<Account>& account) {

    int shirtNum;
    int shirtQuantity=1;
    bool selection = false;
    bool selection2 = false;

    while (selection == false) {

        cout << "Enter the number of the shirt you wish to buy (1-10): ";
        cin >> shirtNum;

        if (shirtNum > 0 && shirtNum < 11) {
            selection = true;
        }

        else {

            cout << "Invalid selction." << endl;
        }

    }

    while (selection == false) {

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






}

void readShirts(vector<Shirts>& shirts);
void readUsers(vector<User>& user);
void readAccount(vector<Account>& account);
void readOrder(vector<Order>& order);

int main() {

    vector<User> user;
    vector<Account> account;
    vector<Order> order;
    vector<Shirts> shirts;
    vector<ShoppingCart> cart;

    readShirts(shirts);

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
            createUser(user);
            createAccount(account);
            break;
        case 2:
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
            displayCartMenu(cart);
            bool exitCartMenu = false;
            while (!exitCartMenu) {
                displayCartMenu();
                cout << "Enter your choice: ";
                int cartChoice;
                cin >> cartChoice;
                switch (cartChoice) {
                case 1:
                    // View items in the cart
                    break;
                case 2:
                    // View the entire cart
                    break;
                case 3:
                    // Add a shirt to the cart
                    break;
                case 4:
                    // Remove a shirt from the cart
                    break;
                case 5:
                    // Enter temporary shipping/billing address
                    break;
                case 6:
                    // Enter temporary payment information
                    break;
                case 7:
                    // Purchase shirts
                    break;
                case 8:
                    cout << "Logging out..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            break;
        }
            break;
        case 3:
            //viewAccount(account);
            displayAccountMenu(account);
            bool exitAccountMenu = false;
            while (!exitAccountMenu) {
                displayAccountMenu();
                cout << "Enter your choice: ";
                int accountChoice;
                cin >> accountChoice;
                switch (accountChoice) {
                case 1:
                    // Edit shipping info
                    break;
                case 2:
                    //  Edit Billing info
                    break;
                case 3:
                    // Edit credit card info
                    break;
                case 4:
                    // view order history
                    break;
                case 5:
                    // delete account
                    break;
                case 6:
                    cout << "Logging out..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
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

    cout << "Account Information:" << endl;
    cout << "1. Edit Shipping" << endl;
    cout << "2. Edit Billing" << endl;
    cout << "3. Edit Credit Card Info" << endl;
    cout << "4. View Order History" << endl;
    cout << "5. Delete Account" << endl;
    cout << "6. Logout" << endl;
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
            endl << "Price: " << shirts[i].getPrice() << "# in Stock: " << shirts[i].getQuantity() << endl;
        cout << endl;

        cout << endl;
    }
}


