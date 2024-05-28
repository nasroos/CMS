cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ClinicManagementSystem)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(clinic_management_system
        main.cpp
        ClinicManagementSystem.cpp
        Patient.cpp
        Appointment.cpp
        Billing.cpp
)

# Include directories
target_include_directories(clinic_management_system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
