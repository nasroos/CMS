#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

class Appointment {
public:
    std::string patientName;
    std::string doctorName;
    time_t appointmentTime;

    void scheduleAppointment(const std::string& filename) const;
    static void displayAppointment(const Appointment& appointment);
    static Appointment deserialize(const std::string& data);
};

#endif // APPOINTMENT_H
