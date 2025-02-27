#include "../include/Staff.hpp"
/*
 Function to validate the format of a phone number string.
 The expected format is "(XXX)-XXX-XXXX", where:
 - XXX is a three-digit area code enclosed in parentheses
 - The area code is followed by a hyphen (-)
 - The next three digits represent the local exchange code
 - The local exchange code is followed by another hyphen (-)
 - Finally, the last four digits represent the subscriber number

 Parameters:
 - phoneNumber: A constant reference to a string representing the phone number to be validated.

 Returns:
 - A boolean value: true if the phone number string matches the expected format, 
   false otherwise.
*/
bool Staff::validatePhoneNumberFormat(const std::string& phoneNumber) {
    std::regex phonePattern(R"(^\(\d{3}\)-\d{3}-\d{4}$)");
    return regex_match(phoneNumber, phonePattern);
}
    void Staff::setStaffInfo(){
        std::cout<<"******************************************************"<<std::endl;
        std::cout<<"Enter full name: ";
        getline(std::cin, name);
        while(true){
            std::cout<<"Role (d = Doctor, n = Nurse, a = auxiliary): ";
            if(std::cin>>role && (role == 'd' || role == 'n' || role == 'a'||role == 'D' || role == 'N' || role == 'A')){
                break;
            } else {
                std::cout<<"Invalid role.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
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
                        std::cout << "This is an auxiliary staff member, prefix must be N\n";
                    }
                }
                
            } else {
                std::cout<<"Invalid staff ID length.\n";
            }
        }
        std::cout << "Enter qualifications: " << std::endl;
        std::cout << "0. None \n";
        for(size_t i=0; i<qualificationsList.size(); i++){
                std::cout<<i+1<<" "<<qualificationsList[i]<<std::endl;
                
        }
        
        std::cout<<"Select whichever applies: "<< std::endl;
        size_t i;
        if (i != 0){
            if(std::cin >> i && i>qualificationsList.size()){
                std::cout<<"Invalid choice.\n";
            } else {
                qualification.push_back(qualificationsList[i-1]);
            } 
        }
        for (std::string s :qualification){
            std::cout<<s<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
void Staff::saveToFile() {
    // Define the file path
    std::string filePathD = "Staff Data/Doctor_Data/" + name + " " + staffId + ".txt";
    std::string filePathN = "Staff Data/Nurse_Data/" + name + " " + staffId + ".txt";
    std::string filePathA = "Staff Data/Auxiliary_Data/" + name + " " + staffId + ".txt";

    // Assign the correct file path based on role
    std::string filePath;
    std::string prefix;
    std::string command;
    if (role == 'D' || role == 'd') {
        filePath = filePathD;
        prefix = "Dr. ";
    } else if (role == 'N' || role == 'n') {
        filePath = filePathN;
        prefix = "Nurse ";
    } else if (role == 'A' || role == 'a') {
        filePath = filePathA;
        if(gender == 'F') {
            prefix = "Ms. ";
        } else if (gender == 'M'){
            prefix = " Mr. ";
        }
    }

    // Open the file for writing
    std::ofstream outfile(filePath);
    if (!outfile.is_open()) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    // Write staff data to the file
    outfile << "Name: " << prefix << name << std::endl;
    if (gender == 'M'){
        outfile << "Gender: Male" << std::endl;
    } else if (gender == 'F'){
        outfile << "Gender: Female" << std::endl;
    }
    outfile << "Phone Number: " << phoneNumber << std::endl;
    outfile << "Staff ID: " << staffId << std::endl;
    outfile << "Specialty: ";
    for (const auto& q : qualification) {
        outfile << q << " ";
    }
    outfile << std::endl;

    outfile.close();
    std::cout << "Staff data saved to " << filePath << std::endl;
}
void Staff::displayStaffData() {
    std::string firstName, lastName, patientId;

    // Prompt the user for patient details
    std::cout << "Enter Staff Name: ";
    getline(std::cin, name);
    std::cout << "Enter Staff ID: ";
    std::cin >> staffId;

    // Assign the correct file path based on role
    std::string filePath;
    if (role == 'D' || role == 'd') {
        filePath = "Staff Data/Doctor_Data/" + name + " " + staffId + ".txt";
    } else if (role == 'N' || role == 'n') {
        filePath = "Staff Data/Nurse_Data/" + name + " " + staffId + ".txt";
    } else if (role == 'A' || role == 'a') {
        filePath = "Staff Data/Auxilary_Data/" + name + " " + staffId + ".txt";
    }

    // Open the file for reading
    std::ifstream infile(filePath);
    try{
        if (!infile.is_open()) {
            std::cerr << "Error: Unable to open file for reading.\n";
            return;
        }
    } catch (const std::exception &e){
        std::cout<<e.what()<<std::endl; 
    }

    // Read and display the patient data
    std::string line;
    std::cout << "******************************************************" << std::endl;
    std::cout << "Staff Data:" << std::endl;
    while (getline(infile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "******************************************************" << std::endl;

    infile.close();
}
