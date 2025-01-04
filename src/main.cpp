#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "../Header Files/Login.h"
#include "../Header Files/Patient.h"
#include "../Header Files/Staff.h"

Patient patient;
std::string patientFname;
std::string patientLname;
std::string pId;

void Reception();
int main(){
    Reception();
    return 0;
}

void Reception(){
    int choice;
    while (choice != 4){
        std::cout << "Welcome to the Reception Desk\n";
        std::cout << "What would you like to do?\n";
        std::cout << "1.Check in Patient\n";
        std::cout << "2.Check out Patient\n";
        std::cout << "3.Request Patient Information\n";
        std::cout << "4.Exit\n";
        if (!(std::cin >> choice)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue; // Skip the rest of the loop and prompt again
        }
        switch (choice) {   
            case 1:
                patient.setPatientData();
                patient.saveToFile();
                break;
            case 2:
                std::cout << "Not implemented:\n";
                break;
            case 3:
                std::cout << "Enter patient First name: ";
                std::cin >> patientFname;
                std::cout << "Enter patient Last name: ";
                std::cin >> patientLname;
                std::cout << "Enter patient ID: ";
                std::cin >> pId;
                if (patient.patientExist(patientFname, patientLname)){
                    patient.displayPatientData(patientFname, patientLname, pId);
                    std::cout << "\n Press Enter to continue...";
                    } else {
                        std::cout << "Patient not found\n";
                    }
                std::cin.ignore();
                std::cin.get();
                break;
            default:
                std::cout << "Invalid command.";
                
        }
    }



}