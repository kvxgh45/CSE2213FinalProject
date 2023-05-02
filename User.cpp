#include <iostream>
#include <string>
#include <vector>
#include "User.h"
using namespace std;

User::User() {

}
// Getters 
string User::getName() {
    return Name;
}
string User::getUsername() {
    return user;
}
string User::getPassword() {
    return Password;
}

// Setters
void User::setName(string name) {
    this->Name = Name;
}
void User::setPassword(string password) {
    this->Password = Password;
}
void User::setUsername(string user) {
    this->user = user;
}