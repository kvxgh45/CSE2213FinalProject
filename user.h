
#include <string>

using std::string;

#ifndef USER_H
#define USER_H


class User
{
private:
    string Name = "", user = "", Password = "";

public:
    User();
    User(string Name, string user, string Password)
    {
        this->Password = Password;
        this->user = user;
        this->Name = Name;
    };

    // getters

    string getName();
    string getUsername();
    string getPassword();

    // setters
    void setName(string name);
    void setPassword(string password);
    void setUsername(string user);
};

#endif // USER_H
