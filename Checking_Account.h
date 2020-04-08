#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"
#include <iostream> 

//Can reuse the deposit functionality in account
//Need to keep logic of withdrawls but rework and implement the transaction fee 

class Checking_Account: public Account {
private: 
    static constexpr const char *def_name = "Unnamed Checking Account"; 
    static constexpr double def_balance = 0.0; 
    static constexpr double def_transaction_fee = 1.5; 
protected: 
    double transaction_fee = def_transaction_fee; 
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) override; //Inherited
    virtual bool withdraw(double amount) override; 
    virtual void print(std::ostream &os) const override; 
    virtual ~Checking_Account() = default; 

};

#endif // _CHECKING_ACCOUNT_H_
