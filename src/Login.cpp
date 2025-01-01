#include "Login.h"

string Login::encrypt(string password) {
    string newPassword = "";
    for (char c : password) {
        newPassword += c + 3;
    }
    return newPassword;
}
string Login::decrypt(string password) {
    string newPassword = "";
    for (char c : password) {
        newPassword += c - 3;
    }
    return newPassword;
}

// Handles user registration
void Login::reg() {
    string username, password, verifyPassword;

    // Prompt the user to enter a username
    cout << "Enter username: ";
    getline(cin, username);

    // Prompt the user to enter a password with at least 8 characters
    cout << "Enter password using 8+ characters (e.g. p@SsW0$d): ";
    cin >> password;

    // Prompt the user to verify the password
    cout << "Enter password to verify: ";
    cin >> verifyPassword;

    // Ensure the password is at least 8 characters long
    while (password.size() < 8) {
        cout << "Password was too short." << endl;
        cout << "Enter password using 8+ characters (e.g. p@SsW0$d): ";
        cin >> password;
        cout << "Enter password to verify: ";
        cin >> verifyPassword;
    }

    // Ensure the password and verification match
    while (password != verifyPassword) {
        cout << "Passwords do not match." << endl;
        cout << "Enter password using 8+ characters (e.g. p@SsW0$d): ";
        cin >> password;
        cout << "Enter password to verify: ";
        cin >> verifyPassword;
    }

    // Check if the username already exists in the database
    ifstream infile("database.txt");
    string line;
    while (getline(infile, line)) {
        if (line.find(username + ":") == 0) {
            cout << "User exists. Try again." << endl;
            infile.close();
            return;
        }
    }

    // Save the new user credentials to the database
    ofstream outfile("database.txt", ios::app);
    outfile << username << ":" << decrypt(password) << endl;
    outfile.close();

    cout << "User  registered successfully!\n";
    infile.close();
}

void Login::login(){
    string username, password;
    cout<<"Enter username: ";
    getline(cin, username);
    cout<<"Enter password: ";
    cin>>password;
    // Check credentials
    ifstream infile("database.txt");
    string line;
    bool loginSuccessful = false;
    while (getline(infile, line)) {
        size_t delimiter = line.find(":");
        string fileUsername = line.substr(0, delimiter);
        string filePassword = line.substr(delimiter + 1);

        if (fileUsername == username && filePassword == decrypt(password)) {
            cout << "Login successful! Welcome, " << username << ".\n";
            loginSuccessful = true;
            break;
        }
    }
    infile.close();

    if (!loginSuccessful) {
        cout << "Invalid username or password. Please try again.\n";
    }

}