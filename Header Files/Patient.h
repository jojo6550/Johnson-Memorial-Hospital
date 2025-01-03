#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <regex>
#include <cstdlib>
#include <dirent.h>
#include <sys/types.h>
class Patient{
    private:
        std::string firstName, lastName, dob, 
        dateOfAdmission, dateOfRelease, wardID, 
        patientId, nextOfKinName, phoneNumber, 
        nextOfKinNumber;
        int age;
        char gender;
    public:
        Patient(){

        }
       Patient(const std::string& fName, const std::string& lName, const std::string& dob, int age, char gender,
        const std::string& phone, const std::string& nokName, const std::string& nokPhone,
        const std::string& admitDate, const std::string& releaseDate, const std::string& ward, const std::string& id)
    : firstName(fName), lastName(lName), dob(dob), dateOfAdmission(admitDate), dateOfRelease(releaseDate),
      wardID(ward), patientId(id), nextOfKinName(nokName), phoneNumber(phone), nextOfKinNumber(nokPhone),
      age(age), gender(gender) {}
// In Patient.h
    bool validateDateFormat(const std::string& date);
    bool validatePhoneNumberFormat(const std::string& phoneNumber);
    void setPatientData();
    void editPatientData();
    void saveToFile();
    void displayPatientData(const std::string& fn, const std::string& ln,const std::string& patientID);
    bool isNextOfKin(const std::string& n) const;
    std::string getPatientId() const;
    bool patientExist(const std::string& fn, const std::string& ln) const;

};