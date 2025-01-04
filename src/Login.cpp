#include <iostream>
#include <fstream>
#include "../Header Files/Login.h"
/**
 * @brief Registers a new user by prompting for username and password.
 *
 * This function handles the user registration process. It prompts the user to enter
 * a username and password, verifies the password, checks for existing usernames,
 * and stores the new user's credentials in a file.
 *
 * The function performs the following steps:
 * 1. Prompts for and validates username input.
 * 2. Prompts for and validates password input (minimum 8 characters).
 * 3. Verifies the password by asking the user to enter it twice.
 * 4. Checks if the username already exists in the users file.
 * 5. If the username is unique, encrypts the password and stores the credentials.
 *
 * @note This function does not take any parameters or return any value.
 *       It interacts with the user via console input/output and modifies the users file.
 */
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

bool Login::login() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cin.ignore(); // Clear the input buffer

    std::ifstream infile("users.txt");
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file 'users.txt' for reading.\n";
    }

    std::string line;
    bool loginSuccessful = false;
    while (getline(infile, line)) {
        size_t delimiter = line.find(":");
        std::string fileUsername = line.substr(0, delimiter);
        std::string filePassword = line.substr(delimiter + 1);

        if (fileUsername == username && filePassword == encrypt(password)) {
            std::cout << "Login successful! Welcome, " << username << ".\n";
            loginSuccessful = true;
            break;
        }
    }
    infile.close();

    if (!loginSuccessful) {
        std::cout << "Invalid username or password. Please try again.\n";
    }
    return loginSuccessful;
}