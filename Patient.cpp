#include "Patient.h"

void Patient::registerPatient(const std::string& filename) const {
    std::ofstream file;
    file.open(filename, std::ios::app);
    file << name << "," << age << "," << gender << "\n";
    file.close();
}

void Patient::displayPatient(const Patient& patient) {
    std::cout << "Name: " << patient.name << std::endl;
    std::cout << "Age: " << patient.age << std::endl;
    std::cout << "Gender: " << patient.gender << std::endl;
}

Patient Patient::deserialize(const std::string& data) {
    Patient patient;
    std::stringstream ss(data);
    std::getline(ss, patient.name, ',');
    ss >> patient.age;
    ss.ignore(1); // ignore the comma
    std::getline(ss, patient.gender);
    return patient;
}
