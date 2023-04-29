
#include <string>

using std::string;

#ifndef USER_H
#define USER_H


class User
{
    private:
        string Password = "", User = "", Name = "";

    public:
        User();
        User(string Password, string User, string Name)
        {
            this->Password = Password;
            this->User = User; 
            this->Name = Name;
        };

        // getters
        
        string getName();
        string getUsername();
        string getPassword();
        
        // setters
        string setName(string name);
        string setPassword(string password);
        string setUsername(string name);
        void logIn(string password ,string user);
        void logOut(); 
};

#endif // USER_H