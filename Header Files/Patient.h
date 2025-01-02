#pragma once
#include <string>
#include <regex>

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
    void displayPatientData();

};