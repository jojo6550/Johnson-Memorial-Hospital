#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <regex>
#include "../Header Files/Login.h"
        
class Patient{
    private:
        std::string firstName, lastName, dob, dateOfAdmission, dateOfRelease, wardID, patientId, nextOfKinName, phoneNumber, nextOfKinNumber;
        int age;
        char gender;
    public:
        Patient(){

        }
        bool validateDateFormat(const std::string& date) {
            std::regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
            return regex_match(date, pattern);
        }
        bool validatePhoneNumberFormat(const std::string& phoneNumber) {
            std::regex phonePattern(R"(^\(\d{3}\)\d{3}-\d{4}$)");
            return regex_match(phoneNumber, phonePattern);
        }
        void setPatientData(){
            std::cout<<"******************************************************"<<std::endl;
            std::cout << "Enter First Name: ";
            std::cin >> firstName;
            std::cout << "Enter Last Name: ";
            std::cin >> lastName;
            //Enters date of birth
            while (true){
                std::cout << "Enter Date of Birth (dd/mm/yyyy): ";
                if (std::cin>>dob && validateDateFormat(dob)){
                    break;
                } else {
                    std::cout << "Invalid date format." <<std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            //Enter age
            while(true){
                std::cout << "Enter Age: ";
                if(std::cin >> age && age >= 0){
                    break;
                } else {
                    std::cout << "Invalid input. Please enter a valid age." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                
            }
            //Enter gender
            while(true){
                std::cout << "Enter Gender (M/F): ";
                if (std::cin>> gender && (gender == 'M' || gender == 'F')){
                    break;
                } else {
                    std::cout << "Invalid input. Please enter a valid gender." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                }
            }
            //Enter phone number
            while (true){
            std::cout << "Enter Phone Number (xxx-xxx-xxxx): ";
                if (std::cin >> phoneNumber && validatePhoneNumberFormat(phoneNumber)){
                    break;
                } else {
                    std::cout << "Invalid date format." <<std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            std::cout<<"******************************************************"<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the entire input buffer
            std::cout << "Enter Next of Kin Name: ";
            getline(std::cin, nextOfKinName); // Now this will work correctly
            
            //Next of Kin Phone Number
            while (true){
                std::cout << "Enter Next of Kin Phone Number (xxx-xxx-xxxx): ";
                if (std::cin >> nextOfKinNumber && validatePhoneNumberFormat(nextOfKinNumber)){
                    break;
                } else {
                    std::cout << "Invalid phone number format." <<std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            std::cout<<"******************************************************"<<std::endl;


            while (true){
                std::cout << "Enter Date of Admission (dd/mm/yyyy): ";
                if (std::cin>>dateOfAdmission && validateDateFormat(dateOfAdmission)){
                    break;
                } else {
                    std::cout << "Invalid date format." <<std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            while (true){
            std::cout << "Enter Date of Release (dd/mm/yyyy): ";
                if (std::cin>>dateOfRelease && validateDateFormat(dateOfRelease)){
                    break;
                } else {
                    std::cout << "Invalid date format." <<std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            std::cout << "Enter Ward ID: ";
            std::cin >> wardID;
            std::cout << "Enter Patient ID: ";
            std::cin >> patientId;
            std::cout<<"******************************************************"<<std::endl;
        }
};
int main() {
    Patient p;
    p.setPatientData();
    
    return 0;
}

// Encrypts the password by shifting each character by 2 positions in the ASCII table
