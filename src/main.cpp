#include <iostream>
#include <string>
#include <limits>
#include "../Header Files/Login.h"
#include "../Header Files/Patient.h"
#include "../Header Files/Staff.h"

Patient patient;
Login user;
std::string patientFname;
std::string patientLname;
std::string pId;

void Reception();
int main(){
    int attempts = 1;
    std::cout << "Welcome to the Hospital Management System!" << std::endl;
    while (true){
        if (user.login()){
            Reception();
            break;
        } else {
            attempts++;
            if (attempts == 5){
                std::cout << "Maximum attempts exceeded. Exiting..." << std::endl;
                return false;
            } else {
                continue;
            }
        }
    }

    return 0;
}

void Reception(){
    int choice;
    while (choice != 3){
        std::cout<<"********************************\n";
        std::cout << "Welcome to the Reception Desk\n";
        std::cout<<"********************************\n";
        std::cout << "1.Check in Patient\n";
        std::cout << "2.Request Patient Information\n";
        std::cout << "3.Exit\n";
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
            case 3:
                std::cout << "Good day!.\n";
                break;
            default:
                std::cout << "Invalid command\n";
                continue;
                
        }
    }



}
