#include "Savings_Account.h"
#include <iostream> 

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account{name, balance}, int_rate{int_rate} {
}

bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount); //Don't need logic since the deposit in the Account class does the logic for us. 
    std::cout << "Savings Account deposit was called with " << amount << std::endl; 
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount); 
}

void Savings_Account::print(std::ostream &os) const {
    os.precision(2); 
    os << std::fixed; 
    os << "[Savings Account " << name << ": " << balance << ", " << int_rate << "%]"; 
}
