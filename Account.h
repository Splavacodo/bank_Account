#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string> 
#include <iostream> 
#include "I_Printable.h"

class Account: public I_Printable {
private: 
    static constexpr const char *def_name = "Unnamed Account"; 
    static constexpr double def_balance = 0.0; 
protected: 
    double balance; 
    std::string name; 
public:
    Account(std::string name = def_name, double balance = def_balance); 
    virtual bool deposit(double amount) = 0; 
    virtual bool withdraw(double amount) = 0; 
    virtual void print(std::ostream &os) const override; 
    double get_balance() const; 
    virtual ~Account() = default; 

};

#endif // _ACCOUNT_H_
