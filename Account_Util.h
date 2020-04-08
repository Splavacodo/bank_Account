#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector> 
#include <memory> 
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h" 

//Utility function for all Account * classes 
//void display(const std::vector<Account *> &accounts);
void display(const std::vector<std::shared_ptr<Account>> &accounts);  
void deposit(std::vector<Account *> &accounts, double amount); 
void withdraw(std::vector<Account *> &accounts, double amount); 


#endif // _ACCOUNT_UTIL_H_
