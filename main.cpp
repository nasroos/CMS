#include <iostream>
#include <unistd.h> // for pipe
#include <string>
#include <cstring>

// Define class for Patient
class Patient {
public:
    std::string name;
    int age;
    std::string gender;

    void registerPatient(int pipe[2]) {
        // Write patient data to pipe
        write(pipe[1], this, sizeof(Patient));
    }

    static void displayPatient(const Patient& patient) {
        std::cout << "Name: " << patient.name << std::endl;
        std::cout << "Age: " << patient.age << std::endl;
        std::cout << "Gender: " << patient.gender << std::endl;
    }
};

// Define class for Appointment
class Appointment {
public:
    std::string patientName;
    std::string doctorName;
    time_t appointmentTime;

    void scheduleAppointment(int pipe[2]) {
        // Write appointment data to pipe
        write(pipe[1], this, sizeof(Appointment));
    }

    static void displayAppointment(const Appointment& appointment) {
        std::cout << "Patient Name: " << appointment.patientName << std::endl;
        std::cout << "Doctor Name: " << appointment.doctorName << std::endl;
        std::cout << "Appointment Time: " << appointment.appointmentTime << std::endl;
    }
};

// Define class for Billing
class Billing {
public:
    std::string patientName;
    float amount;

    void generateBill(int pipe[2]) {
        // Write billing data to pipe
        write(pipe[1], this, sizeof(Billing));
    }

    static void displayBill(const Billing& bill) {
        std::cout << "Patient Name: " << bill.patientName << std::endl;
        std::cout << "Amount: " << bill.amount << std::endl;
    }
};

class ClinicManagementSystem {
private:
    int registrationPipe[2], schedulingPipe[2], billingPipe[2];

public:
    ClinicManagementSystem() {
        // Create pipes
        if (pipe(registrationPipe) < 0 || pipe(schedulingPipe) < 0 || pipe(billingPipe) < 0) {
            std::cerr << "Error: Unable to create pipes.\n";
            return;
        }
    }

    ~ClinicManagementSystem() {
        // Close pipes
        close(registrationPipe[0]);
        close(registrationPipe[1]);
        close(schedulingPipe[0]);
        close(schedulingPipe[1]);
        close(billingPipe[0]);
        close(billingPipe[1]);
    }

    void start() {
        int choice;

        do {
            // Display menu
            std::cout << "\nClinic Management System Menu\n";
            std::cout << "1. Register Patient\n";
            std::cout << "2. Schedule Appointment\n";
            std::cout << "3. Generate Bill\n";
            std::cout << "4. Display Patient\n";
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
                    displayPatient();
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

private:
    void handleRegistration() {
        Patient patient;
        std::cout << "\nEnter patient details:\n";
        std::cout << "Name: ";
        std::cin >> patient.name;
        std::cout << "Age: ";
        std::cin >> patient.age;
        std::cout << "Gender: ";
        std::cin >> patient.gender;
        patient.registerPatient(registrationPipe);
    }

    void handleScheduling() {
        Appointment appointment;
        std::cout << "\nEnter appointment details:\n";
        std::cout << "Patient Name: ";
        std::cin >> appointment.patientName;
        std::cout << "Doctor Name: ";
        std::cin >> appointment.doctorName;
        // Assume appointment time is a UNIX timestamp
        std::cout << "Appointment Time (Unix Timestamp): ";
        std::cin >> appointment.appointmentTime;
        appointment.scheduleAppointment(schedulingPipe);
    }

    void handleBilling() {
        Billing bill;
        std::cout << "\nEnter billing details:\n";
        std::cout << "Patient Name: ";
        std::cin >> bill.patientName;
        std::cout << "Amount: ";
        std::cin >> bill.amount;
        bill.generateBill(billingPipe);
    }

    void displayPatient() {
        // Read patient data from pipe and display
        Patient patient;
        read(registrationPipe[0], &patient, sizeof(Patient));
        std::cout << "\nPatient Information:\n";
        Patient::displayPatient(patient);
    }

    void displayAppointments() {
        // Read appointment data from pipe and display
        Appointment appointment;
        read(schedulingPipe[0], &appointment, sizeof(Appointment));
        std::cout << "\nScheduled Appointment Information:\n";
        Appointment::displayAppointment(appointment);
    }

    void displayBills() {
        // Read bill data from pipe and display
        Billing bill;
        read(billingPipe[0], &bill, sizeof(Billing));
        std::cout << "\nGenerated Bill Information:\n";
        Billing::displayBill(bill);
    }
};

int main() {
    ClinicManagementSystem cms;
    cms.start();
    return 0;
}
