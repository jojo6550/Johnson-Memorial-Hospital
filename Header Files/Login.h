#pragma once
#include <string>

class Login{
    private:
        std::string username, password;
    public:
        Login(std::string user = "Admin", std::string pw = "Password99"){
            username = user;
            password = pw;
        };
            // Function prototypes
        std::string encrypt(std::string password); // Encrypts the password
        std::string decrypt(std::string password); // Decrypts the password
        void login();    // Handles user login (not implemented in this code)
        void reg();                      // Handles user registration
};