#include "Appointment.h"

void Appointment::scheduleAppointment(const std::string& filename) const {
    std::ofstream file;
    file.open(filename, std::ios::app);
    file << patientName << "," << doctorName << "," << appointmentTime << "\n";
    file.close();
}

void Appointment::displayAppointment(const Appointment& appointment) {
    std::cout << "Patient Name: " << appointment.patientName << std::endl;
    std::cout << "Doctor Name: " << appointment.doctorName << std::endl;
    std::cout << "Appointment Time: " << appointment.appointmentTime << std::endl;
}

Appointment Appointment::deserialize(const std::string& data) {
    Appointment appointment;
    std::stringstream ss(data);
    std::getline(ss, appointment.patientName, ',');
    std::getline(ss, appointment.doctorName, ',');
    ss >> appointment.appointmentTime;
    return appointment;
}
