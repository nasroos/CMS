#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Patient {
public:
    std::string name;
    int age;
    std::string gender;

    void registerPatient(const std::string& filename) const;
    static void displayPatient(const Patient& patient);
    static Patient deserialize(const std::string& data);
};

#endif // PATIENT_H
