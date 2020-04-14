#include <iostream> 
#include <memory>
#include <string> 
#include "Account_Util.h"
 
 
 void display(const std::vector<std::shared_ptr<Account>> &accounts) {
    std::cout << "\n------ Accounts -----------------------" << std::endl; 
    for (const auto acc: accounts)
        std::cout << *acc << std::endl; 
}

//Deposit amount to each Account object pointer in the vector 
void deposit(std::vector<std::shared_ptr<Account>> &accounts, double amount) {
    std::cout << "\n------ Depositing to Accounts ------------------------" << std::endl; 
    for (auto acc:accounts) {
        if (acc->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *acc << std::endl; 
        else 
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl; 
    }
}

//Withdraw amount from each Account object pointer in the vector
void withdraw(std::vector<std::shared_ptr<Account>> &accounts, double amount) {
    std::cout << "\n--------- Withdrawing from Accounts ------------------------" << std::endl; 
    for (auto acc:accounts) {
        if (acc->withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl; 
        else
            std::cout << "Failed withdrawl of " << amount << " from " << *acc << std::endl; 
    }
}

void run_program(std::vector<std::shared_ptr<Account>> &accounts){
    do {
        char input = menu(input);
        process_input(accounts, input); 
        if (input == 'Q' || input == 'q'){
            break; 
        }
} while(true); 
}

char menu(char input){
        std::cout << "\nP - Print Accounts" << std::endl; 
        std::cout << "A - Add a new account" << std::endl; 
        std::cout << "D - Deposit to all accounts" << std::endl; 
        std::cout << "W - Withdraw from all accounts" << std::endl; 
        std::cout << "Q - Quit" << std::endl;  
        std::cout << "\nEnter your choice: "; 
        std::cin >> input; 
        return input; 
}

void process_input(std::vector<std::shared_ptr<Account>> &accounts, char input){
    if (input == 'P' || input == 'p'){
        print_accounts(accounts);  
    }
    else if (input == 'A' || input == 'a') {
        add_account(accounts); 
    }
    else if (input == 'D' || input == 'd') {
        deposit_accounts(accounts); 
    }
    else if (input == 'W' || input == 'w') { 
        withdraw_accounts(accounts); 
    }
    else if(input == 'Q' || input == 'q'){
        std::cout << "\nGoodbye" << std::endl;
    } 
    else
        std::cout << "Unknown selection, please try again" << std::endl; 
}

void process_acc_input(std::vector<std::shared_ptr<Account>> &accounts, char account_type) {
    std::string acc_name; 
    double init_amt; 
    if (account_type == 'C' || account_type == 'c') {
        std::cout << "Please enter the name on the account: "; 
        std::cin >> acc_name; 
        std::cout << "\nPlease enter initial amount going into the account: "; 
        std::cin >> init_amt; 
        std::shared_ptr<Checking_Account> c_acc = std::make_shared<Checking_Account>(acc_name, init_amt); 
        accounts.push_back(c_acc); 
        std::cout << "\n" << *c_acc << " was added to your accounts" << std::endl;
    }
    else if (account_type == 'S' || account_type == 's') {
        std::cout << "\nPlease enter the name on the account: ";
        std::cin >> acc_name; 
        std::cout << "\nPlease enter initial amount going into the account: "; 
        std::cin >> init_amt; 
        std::shared_ptr<Savings_Account> s_acc = std::make_shared<Savings_Account>(acc_name, init_amt);
        accounts.push_back(s_acc); 
        std::cout << "\n" << *s_acc << " was added your accounts" << std::endl;
    }
    else if (account_type == 'T' || account_type == 't') {
        std::cout << "\nPlease enter the name on the account: "; 
        std::cin >> acc_name; 
        std::cout << "\nPlease enter initial amount going into the account: "; 
        std::cin >> init_amt; 
        std::shared_ptr<Trust_Account> t_acc = std::make_shared<Trust_Account>(acc_name, init_amt); 
        accounts.push_back(t_acc); 
        std::cout << "\n" << *t_acc << " was added your accounts" << std::endl;
    }
}

void print_accounts(std::vector<std::shared_ptr<Account>> &accounts) {
    if (accounts.size() == 0)
        std::cout << "You haven't opened any accounts, please add a new one." << std::endl; 
    else 
        display(accounts); 
}

void add_account(std::vector<std::shared_ptr<Account>> &accounts) {
    char account_type{}; 
    std::cout << "Please input what kind of account you would like to add" << std::endl;
    std::cout << "Checking(C/c), Savings(S/s), or Trust(T/t): ";
    std::cin >> account_type;  
    process_acc_input(accounts, account_type); 
}

void deposit_accounts(std::vector<std::shared_ptr<Account>> &accounts) {
    double deposit_amt {}; 
    std::cout << "Please enter the amount you would like to deposit: "; 
    std::cin >> deposit_amt; 
    deposit(accounts, deposit_amt); 
}

void withdraw_accounts(std::vector<std::shared_ptr<Account>> &accounts) {
    double withdrawal_amt {}; 
    std::cout << "Please enter the amount you would like to withdraw: "; 
    std::cin >> withdrawal_amt; 
    withdraw(accounts, withdrawal_amt); 
}