#include "Account.h"
#include <iostream> 

Account::Account(std::string name, double balance)
    : name{name}, balance{balance} {
}


bool Account::deposit(double amount){
    if (amount < 0)
        return false; 
    else {
        balance += amount; 
        return true; 
    }
    std::cout << "Account deposit called with " << amount << std::endl; 
}

bool Account::withdraw(double amount) {
    if (balance-amount >= 0) {
        balance -= amount; 
        return true; 
    } 
    else
        return false; 
    std::cout << "Insufficient Funds" << std::endl; 
    std::cout << "Account withdraw called with " << amount << std::endl; 
}

double Account::get_balance() const { 
    return balance; 
} 

void Account::print(std::ostream &os) const {
    os.precision(2); 
    os << std::fixed; 
    os << "[Account " << name << ": " << balance << " ]"; 
}