// classes example
#include <iostream>
#include <string>
#include <vector>
#include "user.h";
using namespace std;

user(){

}
// Getters 
string User::getName(){
    return Name; 
}
string User::getUsername(){
    return User; 
}
string User::getPassword(){
    return Password; 
}

// Setters
string User::setName(string name){ 
    this->Name = Name; 
}
string User::setPassword(string password){
    this-> Password = Password; 
}
string User::setUsername(string name){
    this-> User = User; 
}

void User::logIn(string password ,string user){}
void User::logOut(){}
