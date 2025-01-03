#include <iostream>
#include <string>
#include <vector>
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
        std::cin >> choice;
        switch (choice) {
            
            case 1:
                patient.setPatientData();
                patient.saveToFile();
                break;
            case 2:
                break;
            case 3:
                std::cout << "Enter patient First name: ";
                std::cin >> patientFname;
                std::cout << "Enter patient Last name: ";
                std::cin >> patientLname;
                std::cout << "Enter patient ID: ";
                std::cin >> pId;
                //above is guv
                if (patient.patientExist(patientFname, patientLname)){
                    patient.displayPatientData(patientFname, patientLname, pId);
                    std::cin.get();
                    } else {
                        std::cout << "Patient not found\n";
                    }
                break;
                
        }
    }



}