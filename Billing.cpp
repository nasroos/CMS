#include "Billing.h"

void Billing::generateBill(const std::string& filename) const {
    std::ofstream file;
    file.open(filename, std::ios::app);
    file << patientName << "," << amount << "\n";
    file.close();
}

void Billing::displayBill(const Billing& bill) {
    std::cout << "Patient Name: " << bill.patientName << std::endl;
    std::cout << "Amount: " << bill.amount << std::endl;
}

Billing Billing::deserialize(const std::string& data) {
    Billing bill;
    std::stringstream ss(data);
    std::getline(ss, bill.patientName, ',');
    ss >> bill.amount;
    return bill;
}
