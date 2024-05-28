#include "ClinicManagementSystem.h"
#include <iostream>
#include <fstream>

void ClinicManagementSystem::start() {
    int choice;

    do {
        // Display menu
        std::cout << "\nClinic Management System Menu\n";
        std::cout << "1. Register Patient\n";
        std::cout << "2. Schedule Appointment\n";
        std::cout << "3. Generate Bill\n";
        std::cout << "4. Display Patients\n";
        std::cout << "5. Display Scheduled Appointments\n";
        std::cout << "6. Display Generated Bills\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleRegistration();
                break;
            case 2:
                handleScheduling();
                break;
            case 3:
                handleBilling();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                displayAppointments();
                break;
            case 6:
                displayBills();
                break;
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void ClinicManagementSystem::handleRegistration() {
    Patient patient;
    std::cout << "\nEnter patient details:\n";
    std::cout << "Name: ";
    std::cin >> patient.name;
    std::cout << "Age: ";
    std::cin >> patient.age;
    std::cout << "Gender: ";
    std::cin >> patient.gender;
    patient.registerPatient(patientFile);
}

void ClinicManagementSystem::handleScheduling() {
    Appointment appointment;
    std::cout << "\nEnter appointment details:\n";
    std::cout << "Patient Name: ";
    std::cin >> appointment.patientName;
    std::cout << "Doctor Name: ";
    std::cin >> appointment.doctorName;
    // Assume appointment time is a UNIX timestamp
    std::cout << "Appointment Time (Unix Timestamp): ";
    std::cin >> appointment.appointmentTime;
    appointment.scheduleAppointment(appointmentFile);
}

void ClinicManagementSystem::handleBilling() {
    Billing bill;
    std::cout << "\nEnter billing details:\n";
    std::cout << "Patient Name: ";
    std::cin >> bill.patientName;
    std::cout << "Amount: ";
    std::cin >> bill.amount;
    bill.generateBill(billingFile);
}

void ClinicManagementSystem::displayPatients() {
    std::ifstream file(patientFile);
    std::string line;
    std::cout << "\nPatient Information:\n";
    while (std::getline(file, line)) {
        Patient patient = Patient::deserialize(line);
        Patient::displayPatient(patient);
        std::cout << "-------------------\n";
    }
    file.close();
}

void ClinicManagementSystem::displayAppointments() {
    std::ifstream file(appointmentFile);
    std::string line;
    std::cout << "\nScheduled Appointment Information:\n";
    while (std::getline(file, line)) {
        Appointment appointment = Appointment::deserialize(line);
        Appointment::displayAppointment(appointment);
        std::cout << "-------------------\n";
    }
    file.close();
}

void ClinicManagementSystem::displayBills() {
    std::ifstream file(billingFile);
    std::string line;
    std::cout << "\nGenerated Bill Information:\n";
    while (std::getline(file, line)) {
        Billing bill = Billing::deserialize(line);
        Billing::displayBill(bill);
        std::cout << "-------------------\n";
    }
    file.close();
}
