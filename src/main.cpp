#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/Login.h"
#include "../Header Files/Patient.h"
#include "../Header Files/Staff.h"


int main(){
    //Staff doctor;a
    std::vector<std::string> qualifications = {"General"};
    Staff doctor("Jamie", "(876)-322-4356", "A001", 'a', (qualifications), 'F');
    //doctor.Staff::setStaffInfo();
    
    doctor.saveToFile();
    doctor.displayStaffData();
    return 0;
}
