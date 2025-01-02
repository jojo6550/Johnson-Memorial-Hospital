#include <iostream>
#include "../Header Files/Login.h"
#include "../Header Files/Patient.h"
int main() {
    Patient p("Jamin", "Johnson", "07/05/2006", 18, 'M', "(876)-322-4356", "Janice Johnson", "(876)-771-1865", "01/01/2025","01/01/2026", "Surgical", "P001");
    p.saveToFile();
    p.displayPatientData();
    return 0;
}

// Encrypts the password by shifting each character by 2 positions in the ASCII table
