#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Login{
    private:
        std::string username, password;
    public:
        Login(std::string user = "Admin", std::string pw = "Password99"){
            username = user;
            password = pw;
            // Check if the users.txt file exists, if not create it with default admin user
            std::ifstream infile("users.txt");
            if (!infile.is_open()) {
                std::ofstream outfile("users.txt");
                if (!outfile.is_open()) {
                    std::cerr << "Error: Unable to open file 'users.txt' for writing.\n";
                    return;
                }
                outfile << username << ":" << encrypt(password) << std::endl;
                outfile.close();
                std::cout << "Default admin user created. Please login with username '" << username << "' and password '" << password << "'." << std::endl;
            }
            infile.close();
        };
            // Function prototypes
        std::string encrypt(std::string password); // Encrypts the password
        std::string decrypt(std::string password); // Decrypts the password
        void reg();
        bool login();    // Handles user login (not implemented in this code)                      // Handles user registration
};