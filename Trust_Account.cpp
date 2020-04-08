#include "Trust_Account.h"
#include <iostream> 

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, num_withdrawals{0} {
}

bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amt; 
    return Savings_Account::deposit(amount); //Don't need logic since the deposit in the Savings_Account class does the logic
    std::cout << "Trust Account deposit was called with " << amount << std::endl; 
}

bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= withdrawal_limit || (amount > balance * max_withdraw_percent))
        return false; 
    else {
        ++num_withdrawals; 
        return Savings_Account::withdraw(amount); 
    }
}

void Trust_Account::print(std::ostream &os) const {
    os << "[Trust Account: " << name << ": " << balance << ", " << int_rate << "%, withdrawls: " << num_withdrawals << "]"; 
}

