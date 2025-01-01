#include <iostream>
#include <string>
#include <fstream>
#include "../Header Files/Login.h"
using namespace std;
        
class Patient{
    private:
        string firstName, lastName, dob, dateOfAdmission, dateOfRelease, wardID, patientId, nextOfKinName;
        int age, phoneNumber, nextOfKinNumber;
    public:
        Patient(){

        }
        void setPatientData(){
            cout<<"******************************************************"<<endl;
            cout << "Enter First Name: ";
            cin >> firstName;
            cout << "Enter Last Name: ";
            cin >> lastName;
            cout << "Enter Date of Birth (dd/mm/yyyy): ";
            cin >> dob;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Phone Number (xxx-xxx-xxxx): ";
            cin >> phoneNumber;
            cout<<"******************************************************"<<endl;
            cin.ignore();
            cout << "Enter Next of Kin Name: ";
            getline(cin, nextOfKinName);
            cout << "Enter Next of Kin Phone Number (xxx-xxx-xxxx): ";
            cin >> nextOfKinNumber;
            cout << "Enter Date of Admission (dd/mm/yyyy): ";
            cout<<"******************************************************"<<endl;
            cin >> dateOfAdmission;
            cout << "Enter Date of Release (dd/mm/yyyy): ";
            cin >> dateOfRelease;
            cout << "Enter Ward ID: ";
            cin >> wardID;
            cout << "Enter Patient ID: ";
            cin >> patientId;
            cout<<"******************************************************"<<endl;
        }
};
int main() {
    Patient p;
    p.setPatientData();
    
    return 0;
}

// Encrypts the password by shifting each character by 2 positions in the ASCII table
