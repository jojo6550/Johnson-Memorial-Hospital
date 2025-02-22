#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <regex>
#include <cstdlib>
#include <vector>

class Staff{
    private:
        std::string name ,phoneNumber, staffId;
        std::vector<std::string> qualificationsList = {
            "OBGYN", "Family Physician", "Oncologist",
            "Cardiologist", "Gastroenterologist", "Dermatlogist", 
            "Neurologist", "Pediatrician", "General"};
        std::vector<std::string> qualification = {};

        char role,gender;
    public:
        Staff(){
            
        }
        Staff(std::string n, std::string pn, std::string sId, char r, std::vector <std::string> q, char g){
            name = n;
            phoneNumber = pn;
            staffId = sId;
            role = r;
            qualification = q;
            gender = g;

        }
        bool validatePhoneNumberFormat(const std::string& phoneNumber);
        void setStaffInfo();
        void saveToFile();
        void displayStaffData();
};       