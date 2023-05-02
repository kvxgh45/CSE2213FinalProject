#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Order.h"
#include "Book.h"
#include "ShoppingCart.h"
#include "Account.h"
#include "User.h"

using namespace std;

//Read functions - Opens and reads the associated .txt files and pushes them into a vector
void readShirts(vector<Shirts>& shirts);
void readUsers(vector<User>& user);
void readAccount(vector<Account>& account);
void readOrder(vector<Order>& order);

//Display menu functions
void displayMenu();
void displayCartMenu();
void displayAccountMenu();

//View functions - Reads the items stored in their associated vector and outputs them in certain format
void viewCart(vector<ShoppingCart>& cart);
void viewAccount(vector<Account>& account);
void viewItems(vector<Shirts>& shirts);
void viewOrders(vector<Order>& order);

//Creates random IDs for the order history
string createID();

//Login functions
void createUser(vector<User>& user); //Writes to the user .txt file and vector user-inputted info (Name, Username, Password)
void createAccount(vector<Account>& account); //Writes to the account .txt file and vector user-inputted info (Shipping/Billing address & credit card)
bool login(vector<User>& user); //Compares the user-inputted login credentials with those stored in User.txt

//Edit functions - Takes the currents items stored in the vector and write them into their associated .txt file
void editShirts(vector<Shirts>& shirts);
void editUsers(vector<User>& user);
void editAccount(vector<Account>& account);
void editShipping(vector<Account>& account);
void editBilling(vector<Account>& account);
void editCard(vector<Account>& account);

void addOrder(vector<Order>& order); // Appends order information from a purchase to Order.txt

//Shopping cart functions - Adds & removes items from the shopping cart vector until a purchase is made, clearing the vector
void purchase(vector<Shirts>& shirts, vector<ShoppingCart>& cart, vector<Order>& order);
void addShirt(vector<Shirts>& shirts, vector<ShoppingCart>& cart, vector<Account>& account);
void removeShirt(vector<ShoppingCart>& cart);

//Resets the program, deletting user, account, and order history information. Also resets the shirts inventory with the backup file
void deleteAccount(vector<User>& user, vector<Account>& account, vector<Order>& order, vector<Shirts>& shirts);

int main() {

    vector<User> user;
    vector<Account> account;
    vector<Order> order;
    vector<Shirts> shirts;
    vector<ShoppingCart> cart;

    //Login Menu

    bool loggedIn = false;

    while (true) { //Loops until the user logs in or exits the menu
        cout << "Start Menu:" << endl;
        cout << "1. Create an account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: // Creates a new user, prompting user for login and account info
            createUser(user);
            createAccount(account);
            break;
        case 2:
            readUsers(user);
            loggedIn = login(user); //compares the user login info (username & password) with that stored in the User.txt file
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
        bool exitCart = false;
        bool exitAccount = false;
        displayMenu();
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: //View the shirts in the inventory
            viewItems(shirts);
            break;
        case 2: //Opens the shopping cart menu

            while(true){
                displayCartMenu();

                int cartChoice;
                cout << "Select an option: ";
                cin >> cartChoice;
                switch (cartChoice) {

                case 1: //View the shirts inventory for reference and their item number
                    viewItems(shirts);
                    break;

                case 2: //Vies the shirts currently in the user's cart
                    viewCart(cart);
                    break;

                case 3: //Prompts the user to select a shirt number to add to their cart
                    addShirt(shirts, cart, account);
                    break;

                case 4: //Prompts the user to select a shirt from their cart to remove
                    removeShirt(cart);
                    break;

                case 5: //Purchases all items in the cart, displaying the total cost
                    purchase(shirts, cart, order);
                    exitCart = true;
                    break;

                case 6: //Goes back to the main menu
                    exitCart = true;
                    cout << endl;
                    break;


                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;

                }

                if (exitCart) { break; };
            }
            break;
        case 3: //Opens the account menu

            while (true) {
                displayAccountMenu();

                int accChoice;
                cout << "Select an option: ";
                cin >> accChoice;
                cout << endl;
                switch (accChoice) {

                case 1: //Displays the user's current account info (shipping, billing, credit card)
                    viewAccount(account);
                    break;

                case 2: //Prompts the user to change their shipping address
                    editShipping(account);
                    break;

                case 3: //Prompts the user to change their billing address
                    editBilling(account);
                    break;

                case 4: //Prompts the user to change their credit card info
                    editCard(account);
                    break;

                case 5: //Displays the order history tied to the user
                    viewOrders(order);
                    break;

                case 6: //Deletes all information of the user, resets shirt inventory, and resets order history
                    deleteAccount(user, account, order, shirts);
                    exitAccount = true;
                    return 0;
                    break;

                case 7: //Goes back to the main menu
                    exitAccount = true;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;

                }

                if (exitAccount) { break; };
            }
            break;

        case 4: //Logout
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

    cout << "Shopping cart menu options:" << endl;
    cout << "1. View items" << endl;
    cout << "2. View cart" << endl;
    cout << "3. Add shirt" << endl;
    cout << "4. Remove shirt" << endl;
    cout << "5. Purchase shirts" << endl;
    cout << "6. Go back" << endl;
}
void displayAccountMenu() {

    cout << "Account menu options:" << endl;
    cout << "1. View account information" << endl;
    cout << "2. Change shipping address" << endl;
    cout << "3. Change billing address" << endl;
    cout << "4. Credit cart information" << endl;
    cout << "5. View Order History" << endl;
    cout << "6. Delete account" << endl;
    cout << "7. Go Back" << endl;
}

void viewCart(vector<ShoppingCart>& cart) {

    if (cart.empty()) { //Checks to see if the user has added any shirts to their cart first

        cout << endl << "Your cart is currently empty. Please add a shirt first." << endl << endl;
    }

    else {

        cout << "Here is your current shopping cart: " << endl << endl;

        for (int i = 0; i < cart.size(); i++) { //Displays a formatted output for each item added to the cart

            cout << i + 1 << ") ----------" << endl;
            cout << "Shirt Name: " << cart[i].getItemName() << " - Quantity: " << cart[i].getQuantity() << endl;
            cout << "Price: $" << stod(cart[i].getPrice()) * stod(cart[i].getQuantity()) << endl << endl;
        }

        cout << "Shipping address: " << cart[0].getShipping() << endl;
        cout << "Billing address: " << cart[0].getBilling() << endl;
        cout << "Credit card information: " << cart[0].getPayment() << endl << endl;
    }

}
void viewAccount(vector<Account>& account) {

    cout << "Here is your account information: " << endl << endl;
    account.clear();
    readAccount(account);

    cout << "Shipping address: " << account[0].getShipping() << endl;
    cout << "Billing adddress: " << account[0].getBilling() << endl;
    cout << "Payment information: " << account[0].getPayment() << endl << endl;
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

void editShipping(vector<Account>& account) {

    string newShipping;
    cout << "Enter your new shipping address: ";
    cin >> newShipping;

    ofstream outfile;
    outfile.open("Account.txt");

    string billing = account[0].getBilling();
    string card = account[0].getPayment();

    Account tmp(newShipping, billing, card);
    account.clear();
    account.push_back(tmp);

    outfile << account[0].getShipping() << endl;
    outfile << account[0].getBilling() << endl;
    outfile << account[0].getPayment() << endl;
    outfile << endl;

    outfile.close();

    cout << "Shipping address changed!" << endl << endl;

}
void editBilling(vector<Account>& account) {

    string newBilling;
    cout << "Enter your new billing address: ";
    cin >> newBilling;

    ofstream outfile;
    outfile.open("Account.txt");

    string shipping = account[0].getShipping();
    string card = account[0].getPayment();

    Account tmp(shipping, newBilling, card);
    account.clear();
    account.push_back(tmp);

    outfile << account[0].getShipping() << endl;
    outfile << account[0].getBilling() << endl;
    outfile << account[0].getPayment() << endl;
    outfile << endl;

    outfile.close();

    cout << "Billing address changed!" << endl << endl;
}
void editCard(vector<Account>& account) {

    string newCard;
    cout << "Enter your new credit card information: ";
    cin >> newCard;

    ofstream outfile;
    outfile.open("Account.txt");

    string billing = account[0].getBilling();
    string shipping = account[0].getShipping();

    Account tmp(shipping, billing, newCard);
    account.clear();
    account.push_back(tmp);

    outfile << account[0].getShipping() << endl;
    outfile << account[0].getBilling() << endl;
    outfile << account[0].getPayment() << endl;
    outfile << endl;

    outfile.close();

    cout << "Payment information changed!" << endl << endl;
}

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

void purchase(vector<Shirts>& shirts, vector<ShoppingCart>& cart, vector<Order>& order) {

    shirts.clear();
    readShirts(shirts);

    //Calculating total cost and outputting to user
    double totalCost = 0;

    for (int i = 0; i < cart.size(); i++) {

        totalCost += round((stod(cart[i].getPrice())) * (stod(cart[i].getQuantity())));
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

    Order newOrder(ID, orderList, to_string(totalCost), quantityList, cart[0].getShipping());
    order.clear();
    order.push_back(newOrder);
    addOrder(order);

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

void addShirt(vector<Shirts>& shirts, vector<ShoppingCart>& cart, vector<Account>& account) {

    shirts.clear();
    account.clear();
    readShirts(shirts);
    readAccount(account);

    int shirtNum;
    int shirtQuantity = 1;
    bool selection = false;
    bool selection2 = false;

    while (selection == false) {

        cout << endl <<  "Enter the number of the shirt you wish to buy (1-10): ";
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

        cart.erase(cart.begin() + (numItem - 1));

        cout << "Shirt removed!" << endl << endl;

    }
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
        shipping = line;

        getline(infile, line);
        billing = line;

        getline(infile, line);
        payment = line;

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

    shirts.clear();
    readShirts(shirts);

    cout << "Viewing items..." << endl << "-------------------" << endl;
    for (int i = 0; i < shirts.size(); i++)
    {
        cout << i + 1 << ") " << shirts[i].getBrand() << " " << shirts[i].getStyle() << " | Size: ";
        cout << shirts[i].getSize() << " Color: " << shirts[i].getColor() << " Fabric: " << shirts[i].getFabric();
        cout << endl << "Price: $" << shirts[i].getPrice() << " # in Stock: " << shirts[i].getQuantity() << endl;
        cout << endl;
    }
}

void viewOrders(vector<Order>& order) {

    order.clear();
    readOrder(order);

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

string createID() {

    srand((unsigned)time(nullptr));
    string ID;

    for (int i = 0; i < 10; i++) {

        ID += to_string(rand() % 10);
    }

    return ID;
}

void deleteAccount(vector<User>& user, vector<Account>& account, vector<Order>& order, vector<Shirts>& shirts) {

    cout << "Deleting account..." << endl;

    user.clear();
    ofstream outUser;
    outUser.open("User.txt", ios::out | ios::trunc);
    outUser.close();
    

    order.clear();
    ofstream outOrder;
    outOrder.open("Order.txt", ios::out | ios::trunc);
    outOrder.close();

    ofstream outAccount;
    outAccount.open("Account.txt", ios::out | ios::trunc);
    outAccount.close();

    shirts.clear();
    ifstream infile;
    infile.open("ShirtsInventory2.txt");

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

    editShirts(shirts);

    cout << "Account deleted! Thank you for your time!" << endl;

}