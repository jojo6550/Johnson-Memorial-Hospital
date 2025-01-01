#include <iostream>
#include <string>
#include <fstream>
#include "../Header Files/Login.h"
using namespace std;
        

int main() {
    Login user;
    user.login();
    
    return 0;
}

// Encrypts the password by shifting each character by 2 positions in the ASCII table
