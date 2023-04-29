#include <iostream>
#include <string>

struct Account {
    std::string username;
    std::string password;
};

bool createAccount(Account& account) {
    std::cout << "Create an Account" << std::endl;
    std::cout << "Username: ";
    std::cin >> account.username;

    std::cout << "Password: ";
    std::cin >> account.password;

    std::cout << "Account created successfully!" << std::endl;
    return true;
}

bool login(Account& account) {
    std::string username, password;

    std::cout << "Login" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    std::cin >> password;

    if (username == account.username && password == account.password) {
        std::cout << "Login successful!" << std::endl;
        return true;
    } else {
        std::cout << "Login failed. Please try again." << std::endl;
        return false;
    }
}

void displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. View items" << std::endl;
    std::cout << "2. View Cart" << std::endl;
    std::cout << "3. View Account" << std::endl;
    std::cout << "4. Logout" << std::endl;
}

void viewItems() {
    std::cout << "Viewing items..." << std::endl;
}

void viewCart() {
    std::cout << "Viewing cart..." << std::endl;
}

void viewAccount() {
    std::cout << "Viewing account..." << std::endl;
}

int main() {
    Account userAccount;
    bool loggedIn = false;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Create an account" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                createAccount(userAccount);
                break;
            case 2:
                loggedIn = login(userAccount);
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        if (loggedIn) {
            break;
        }
    }

    // Main program loop
    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                viewItems();
                break;
            case 2:
                viewCart();
                break;
            case 3:
                viewAccount();
                break;
            case 4:
                std::cout << "Logging out..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
