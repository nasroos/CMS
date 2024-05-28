#ifndef CLINIC_MANAGEMENT_SYSTEM_H
#define CLINIC_MANAGEMENT_SYSTEM_H

#include "Patient.h"
#include "Appointment.h"
#include "Billing.h"

class ClinicManagementSystem {
public:
    void start();

private:
    void handleRegistration();
    void handleScheduling();
    void handleBilling();
    void displayPatients();
    void displayAppointments();
    void displayBills();

    const std::string patientFile = "patients.txt";
    const std::string appointmentFile = "appointments.txt";
    const std::string billingFile = "bills.txt";
};

#endif // CLINIC_MANAGEMENT_SYSTEM_H
