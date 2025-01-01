#include <iostream>
#include <fstream>
#include "../Header Files/Login.h"

std::string Login::encrypt(std::string password) {
    std::string newPassword = "";
    for (char c : password) {
        newPassword += c + 3;
    }
    return newPassword;
}

std::string Login::decrypt(std::string password) {
    std::string newPassword = "";
    for (char c : password) {
        newPassword += c - 3;
    }
    return newPassword;
}

void Login::reg() {
    std::string username, password, verifyPassword;

    std::cout << "Enter username: ";
    getline(std::cin, username);

    std::cout << "Enter password using 8+ characters (e.g. p@SsW0$d): ";
    std::cin >> password;
    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter password to verify: ";
    std::cin >> verifyPassword;
    std::cin.ignore(); // Clear the input buffer

    while (password.size() < 8) {
        std::cout << "Password was too short." << std::endl;
        std::cout << "Enter password using 8+ characters (e.g. p@SsW0$d): ";
        std::cin >> password;
        std::cin.ignore(); // Clear the input buffer
        std::cout << "Enter password to verify: ";
        std::cin >> verifyPassword;
        std::cin.ignore(); // Clear the input buffer
    }

    while (password != verifyPassword) {
        std::cout << "Passwords do not match." << std::endl;
        std::cout << "Enter password using 8+ characters (e.g. p@SsW0$d): ";
        std::cin >> password;
        std::cin.ignore(); // Clear the input buffer
        std::cout << "Enter password to verify: ";
        std::cin >> verifyPassword;
        std::cin.ignore(); // Clear the input buffer
    }

    std::ifstream infile("users.txt");
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file 'users.txt' for reading.\n";
        return;
    }

    std::string line;
    while (getline(infile, line)) {
        if (line.find(username + ":") == 0) {
            std::cout << "User  exists. Try again." << std::endl;
            infile.close();
            return;
        }
    }
    infile.close();

    std::ofstream outfile("users.txt", std::ios::app);
    if (!outfile.is_open()) {
        std::cerr << "Error: Unable to open file 'users.txt' for writing.\n";
        return;
    }
    outfile << username << ":" << encrypt(password) << std::endl;
    outfile.close();

    std::cout << "User  registered successfully!\n";
}

void Login::login() {
    std::string username, password;
    std::cout << "Enter username: ";
    getline(std::cin, username);
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cin.ignore(); // Clear the input buffer

    std::ifstream infile("users.txt");
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file 'users.txt' for reading.\n";
        return;
    }

    std::string line;
    bool loginSuccessful = false;
    while (getline(infile, line)) {
        size_t delimiter = line.find(":");
        std::string fileUsername = line.substr(0, delimiter);
        std::string filePassword = line.substr(delimiter + 1);

        if (fileUsername == username && filePassword == decrypt(password)) {
            std::cout << "Login successful! Welcome, " << username << ".\n";
            loginSuccessful = true;
            break;
        }
    }
    infile.close();

    if (!loginSuccessful) {
        std::cout << "Invalid username or password. Please try again.\n";
    }
}