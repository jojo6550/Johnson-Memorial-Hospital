#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <regex>
#include <cstdlib>
#include <vector>
#include "../Header Files/Login.h"
#include "../Header Files/Patient.h"

class Staff{
    private:
        std::string name ,phoneNumber, staffId;
        std::vector<std::string> qualificationsList = {
            "OBGYN", "Family Physician", "Oncologist",
            "Cardiologist", "Gastroenterologist", "Dermatlogist", 
            "Neurologist", "Pediatrician", "General"};
        std::vector<std::string> qualification = {};

        char role;
    public:
        Staff(){
            
        }
        Staff(std::string n, std::string pn, std::string sId, char r, std::vector <std::string> q){
            name = n;
            phoneNumber = pn;
            staffId = sId;
            role = r;
            qualification = q;

        }

        bool validatePhoneNumberFormat(const std::string& phoneNumber) {
            std::regex phonePattern(R"(^\(\d{3}\)-\d{3}-\d{4}$)");
            return regex_match(phoneNumber, phonePattern);
        }
        void setStaffInfo(){
            std::cout<<"******************************************************"<<std::endl;
            std::cout<<"Enter full name: ";
            getline(std::cin, name);
            while(true){
                std::cout<<"Role (d = Doctor, n = Nurse, a = auxillary): ";
                if(std::cin>>role && (role == 'd' || role == 'n' || role == 'a'||role == 'D' || role == 'N' || role == 'A')){
                    break;
                } else {
                    std::cout<<"Invalid role.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            while(true){
                std::cout<<"Enter phone number (xxx)-xxx-xxxx: ";
                if(std::cin>>phoneNumber && validatePhoneNumberFormat(phoneNumber)){
                    break;
                } else {
                    std::cout<<"Invalid phone number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            while(true){
                std::cout<<"Enter staff ID (must begin with D, N or A. e.g A001): ";
                if(std::cin>>staffId && staffId.length() == 4){
                    if(role == 'D' || role == 'd' ){
                        if(staffId[0] == 'D'){
                            break;
                        } else {
                            std::cout << "This is a doctor, prefix must be D\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    if(role == 'N' || role == 'n'){
                        if(staffId[0] == 'N'){
                            break;
                        } else {
                            std::cout << "This is a nurse, prefix must be N\n";
                        }
                    }
                    if(role == 'A' || role == 'a'){
                        if(staffId[0] == 'A'){
                            break;
                        } else {
                            std::cout << "This is an auxillary staff member, prefix must be N\n";
                        }
                    }
                    
                } else {
                    std::cout<<"Invalid staff ID length.\n";
                }
            }
            std::cout << "Enter qualifications: " << std::endl;
            for(size_t i=0; i<qualificationsList.size(); i++){
                    std::cout<<i+1<<" "<<qualificationsList[i]<<std::endl;
                    
            }
            std::cout<<"Select all that appply: "<< std::endl;
            //add data entry
        }
};

int main(){
    Staff doctor;
    doctor.setStaffInfo();
    return 0;
}

// Encrypts the password by shifting each character by 2 positions in the ASCII table
