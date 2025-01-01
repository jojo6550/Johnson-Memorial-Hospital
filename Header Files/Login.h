#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Login{
    private:
        string username, password;
    public:
        Login(string user = "Admin", string pw = "Password99"){
            username = user;
            password = pw;
        };
            // Function prototypes
        string encrypt(string password); // Encrypts the password
        string decrypt(string password); // Decrypts the password
        void login();    // Handles user login (not implemented in this code)
        void reg();                      // Handles user registration
};