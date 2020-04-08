#include "Checking_Account.h"
#include <iostream> 

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += transaction_fee; 
    return Account::withdraw(amount); //Don't need logic since the withdraw method in the Account class does the logic for us. 
    std::cout << "Checking Account deposit was called with " << amount << std::endl; 
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount); 
}

void Checking_Account::print(std::ostream &os) const {
    os.precision(2); 
    os << std::fixed; 
    os << "[Checking Account " << name << ": " << balance << "]"; 
}

