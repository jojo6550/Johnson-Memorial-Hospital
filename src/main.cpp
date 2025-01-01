#include <iostream>
#include <string>
#include <fstream>
#include <limits>
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
            while(true){
                cout << "Enter Age: ";
                if(cin >> age && age >= 0){
                    break;
                } else {
                    cout << "Invalid input. Please enter a valid age." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                
            }
            cout << "Enter Phone Number (xxx-xxx-xxxx): ";
            cin >> phoneNumber;
            cout<<"******************************************************"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the entire input buffer
            cout << "Enter Next of Kin Name: ";
            getline(cin, nextOfKinName); // Now this will work correctly
            cout << "Enter Next of Kin Phone Number (xxx-xxx-xxxx): ";
            cin >> nextOfKinNumber;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer after cin
            cout << "Enter Date of Admission (dd/mm/yyyy): ";
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
