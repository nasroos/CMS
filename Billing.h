#ifndef BILLING_H
#define BILLING_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Billing {
public:
    std::string patientName;
    float amount;

    void generateBill(const std::string& filename) const;
    static void displayBill(const Billing& bill);
    static Billing deserialize(const std::string& data);
};

#endif // BILLING_H
