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
char menu(char input); 
void process_input(std::vector<std::shared_ptr<Account>> &accounts, char input); 
void run_program(std::vector<std::shared_ptr<Account>> &accounts); 
void print_accounts(std::vector<std::shared_ptr<Account>> &accounts); 
void add_account(std::vector<std::shared_ptr<Account>> &accounts); 
void deposit_accounts(std::vector<std::shared_ptr<Account>> &accounts); 
void withdraw_accounts(std::vector<std::shared_ptr<Account>> &accounts); 
void process_acc_input(std::vector<std::shared_ptr<Account>> &accounts, char account_type); 

#endif // _ACCOUNT_UTIL_H_
