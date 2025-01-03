#include "../Header Files/Patient.h"

bool Patient::validateDateFormat(const std::string& date) {
            std::regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
            return regex_match(date, pattern);
        }
bool Patient::validatePhoneNumberFormat(const std::string& phoneNumber) {
            std::regex phonePattern(R"(^\(\d{3}\)-\d{3}-\d{4}$)");
            return regex_match(phoneNumber, phonePattern);
        }
void Patient::setPatientData(){
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
                std::cout << "Invalid phone number format." <<std::endl;
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
void Patient::editPatientData() {
        int choice;
        std::string newValue;
        // Ask for patient details to locate the file
        std::string firstName, lastName, patientId;
        std::cout << "Enter Patient First Name: ";
        std::cin >> firstName;
        std::cout << "Enter Patient Last Name: ";
        std::cin >> lastName;
        std::cout << "Enter Patient ID: ";
        std::cin >> patientId;
         // Construct the file path based on the patient ID
        std::string filePath = "Patient Data/" + firstName + " " + lastName + " " + patientId + "/patient_data.txt";

        // Open the file for reading
        std::ifstream infile(filePath);
        if (!infile.is_open()) {
            std::cerr << "Error: Unable to open file for reading.\n";
            return;
        }

        // Read the existing patient data into the object
        std::string line;
        while (getline(infile, line)) {
            size_t delimiter = line.find(": ");
            if (delimiter != std::string::npos) {
                std::string key = line.substr(0, delimiter);
                std::string value = line.substr(delimiter + 2);

                if (key == "First Name") firstName = value;
                else if (key == "Last Name") lastName = value;
                else if (key == "Date of Birth") dob = value;
                else if (key == "Age") age = std::stoi(value);
                else if (key == "Gender") gender = value[0];
                else if (key == "Phone Number") phoneNumber = value;
                else if (key == "Next of Kin Name") nextOfKinName = value;
                else if (key == "Next of Kin Phone Number") nextOfKinNumber = value;
                else if (key == "Date of Admission") dateOfAdmission = value;
                else if (key == "Date of Release") dateOfRelease = value;
                else if (key == "Ward ID") wardID = value;
                else if (key == "Patient ID") patientId = value;
            }
        }
        infile.close();
        while (true) {
            std::cout << "******************************************************" << std::endl;
            std::cout << "Select the field to edit:" << std::endl;
            std::cout << "1. First Name" << std::endl;
            std::cout << "2. Last Name" << std::endl;
            std::cout << "3. Date of Birth" << std::endl;
            std::cout << "4. Age" << std::endl;
            std::cout << "5. Gender" << std::endl;
            std::cout << "6. Phone Number" << std::endl;
            std::cout << "7. Next of Kin Name" << std::endl;
            std::cout << "8. Next of Kin Phone Number" << std::endl;
            std::cout << "9. Date of Admission" << std::endl;
            std::cout << "10. Date of Release" << std::endl;
            std::cout << "11. Ward ID" << std::endl;
            std::cout << "12. Patient ID" << std::endl;
            std::cout << "13. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice == 13) {
                break;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

            switch (choice) {
                case 1:
                    std::cout << "Enter new First Name: ";
                    std::cin >> firstName;
                    break;
                case 2:
                    std::cout << "Enter new Last Name: ";
                    std::cin >> lastName;
                    break;
                case 3:
                    while (true) {
                        std::cout << "Enter new Date of Birth (dd/mm/yyyy): ";
                        if (std::cin >> newValue && validateDateFormat(newValue)) {
                            dob = newValue;
                            break;
                        } else {
                            std::cout << "Invalid date format." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                case 4:
                    while (true) {
                        std::cout << "Enter new Age: ";
                        if (std::cin >> age && age >= 0) {
                            break;
                        } else {
                            std::cout << "Invalid input. Please enter a valid age." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                case 5:
                    while (true) {
                        std::cout << "Enter new Gender (M/F): ";
                        if (std::cin >> gender && (gender == 'M' || gender == 'F')) {
                            break;
                        } else {
                            std::cout << "Invalid input. Please enter a valid gender." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                case 6:
                    while (true) {
                        std::cout << "Enter new Phone Number (xxx-xxx-xxxx): ";
                        if (std::cin >> newValue && validatePhoneNumberFormat(newValue)) {
                            phoneNumber = newValue;
                            break;
                        } else {
                            std::cout << "Invalid phone number format." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                case 7:
                    std::cout << "Enter new Next of Kin Name: ";
                    getline(std::cin, nextOfKinName);
                    break;
                case 8:
                    while (true) {
                        std::cout << "Enter new Next of Kin Phone Number (xxx-xxx-xxxx): ";
                        if (std::cin >> newValue && validatePhoneNumberFormat(newValue)) {
                            nextOfKinNumber = newValue;
                            break;
                        } else {
                            std::cout << "Invalid phone number format." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                case 9:
                    while (true) {
                        std::cout << "Enter new Date of Admission (dd/mm/yyyy): ";
                        if (std::cin >> newValue && validateDateFormat(newValue)) {
                            dateOfAdmission = newValue;
                            break;
                        } else {
                            std::cout << "Invalid date format." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                case 10:
                    while (true) {
                        std::cout << "Enter new Date of Release (dd/mm/yyyy): ";
                        if (std::cin >> newValue && validateDateFormat(newValue)) {
                            dateOfRelease = newValue;
                            break;
                        } else {
                            std::cout << "Invalid date format." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                case 11:
                    std::cout << "Enter new Ward ID: ";
                    std::cin >> wardID;
                    break;
                case 12:
                    std::cout << "Enter new Patient ID: ";
                    std::cin >> patientId;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        }
    // Save the updated patient data back to the file
    std::ofstream outfile(filePath);
    if (!outfile.is_open()) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    outfile << "First Name: " << this->firstName << std::endl;
    outfile << "Last Name: " << this->lastName << std::endl;
    outfile << "Date of Birth: " << this->dob << std::endl;
    outfile << "Age: " << this->age << std::endl;
    outfile << "Gender: " << this->gender << std::endl;
    outfile << "Phone Number: " << this->phoneNumber << std::endl;
    outfile << "Next of Kin Name: " << this->nextOfKinName << std::endl;
    outfile << "Next of Kin Phone Number: " << this->nextOfKinNumber << std::endl;
    outfile << "Date of Admission: " << this->dateOfAdmission << std::endl;
    outfile << "Date of Release: " << this->dateOfRelease << std::endl;
    outfile << "Ward ID: " << this->wardID << std::endl;
    outfile << "Patient ID: " << this->patientId << std::endl;

    outfile.close();
    std::cout << "Patient data updated successfully." << std::endl;    
    }
void Patient::saveToFile() {
        // Define the file path
    std::string filePath = "Patient Data/" + firstName + " " + lastName + " " + patientId + "/patient_data.txt";

        // Ensure the directory exists (manually)
        std::string command = "mkdir \"Patient Data\\" + firstName + " " + lastName + " " + patientId + "\"";
        system(command.c_str());

            // Open the file for writing
            std::ofstream outfile(filePath);
            if (!outfile.is_open()) {
                std::cerr << "Error: Unable to open file for writing.\n";
                return;
            }

            // Write patient data to the file
            outfile << "First Name: " << firstName << std::endl;
            outfile << "Last Name: " << lastName << std::endl;
            outfile << "Date of Birth: " << dob << std::endl;
            outfile << "Age: " << age << std::endl;
            outfile << "Gender: " << gender << std::endl;
            outfile << "Phone Number: " << phoneNumber << std::endl;
            outfile << "Next of Kin Name: " << nextOfKinName << std::endl;
            outfile << "Next of Kin Phone Number: " << nextOfKinNumber << std::endl;
            outfile << "Date of Admission: " << dateOfAdmission << std::endl;
            outfile << "Date of Release: " << dateOfRelease << std::endl;
            outfile << "Ward ID: " << wardID << std::endl;
            outfile << "Patient ID: " << patientId << std::endl;

            outfile.close();
            std::cout << "Patient data saved to " << filePath << std::endl;
        }
void Patient::displayPatientData(const std::string& fn, const std::string& ln, const std::string& pId) {
        //std::string firstName, lastName, patientId;

        // Construct the file path based on the patient details
        std::string filePath = "Patient Data/" + fn + " " + ln + " " + pId + "/patient_data.txt";

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
        std::cout << "Patient Data:" << std::endl;
        while (getline(infile, line)) {
            std::cout << line << std::endl;
        }
        std::cout << "******************************************************" << std::endl;

        infile.close();
    }

bool Patient::patientExist(const std::string& fn, const std::string& ln) const {
    // Define the directory path
    std::string dirPath = "Patient Data/";

    // Check if the directory exists
    DIR* dir;
    if ((dir = opendir(dirPath.c_str())) != NULL) {
        // Iterate through the files in the directory
        dirent* ent;
        while ((ent = readdir(dir)) != NULL) {
            // Check if the file name matches the provided first name and last name
            std::string fileName = ent->d_name;
            size_t spacePos = fileName.find(' ');
            if (spacePos != std::string::npos) {
                std::string name = fileName.substr(0, spacePos);
                size_t secondSpacePos = fileName.find(' ', spacePos + 1);
                if (secondSpacePos != std::string::npos) {
                    std::string lastName = fileName.substr(spacePos + 1, secondSpacePos - spacePos - 1);
                    if (name == fn && lastName == ln) {
                        closedir(dir);
                        return true;
                    }
                }
            }
        }
        closedir(dir);
    }
    return false;
}