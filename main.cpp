#include <iostream> 
#include <memory>
#include "Account.h" 
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std; 

int main() {
    
    Checking_Account jason {"Jason", 5000}; 
    cout << jason << endl; 
     
    std::unique_ptr<Trust_Account> trust = make_unique<Trust_Account>("James"); 
    cout << *trust << endl; 
    
    //Account *p1 = new Checking_Account("Larry", 10000); 
    std::shared_ptr<Checking_Account> p1 = make_shared<Checking_Account>("Larry", 10000); 
    //Account *p2 = new Savings_Account("Moe", 1000);
    std::shared_ptr<Savings_Account> p2 = make_shared<Savings_Account>("Moe", 1000); 
    //Account *p3 = new Trust_Account("Curly"); 
    std::shared_ptr<Trust_Account> p3 = make_shared<Trust_Account>("Curly"); 
    
    //std::vector<Account *> accounts {p1, p2, p3}; //Takes raw pointers
    std::vector<std::shared_ptr<Account>> accounts{p1, p2, p3}; 
    
    display(accounts); 
    //deposit(accounts, 1000); 
    //withdraw(accounts, 2000); 
    
    //display(accounts); 
    
    //delete p1; 
    //delete p2; 
    //delete p3; 
    
    
    /*
    cout.precision(2); 
    cout << fixed; 
    
    //Accounts
    vector<Account> accounts; 
    accounts.push_back(Account{}); 
    accounts.push_back(Account{"Larry"}); 
    accounts.push_back(Account{"Moe", 2000}); 
    accounts.push_back(Account{"Curly", 5000}); 
    
    display(accounts); 
    deposit(accounts, 1000); 
    withdraw(accounts, 2000); 
 
    //Savings
    
    vector<Savings_Account> sav_accounts; 
    sav_accounts.push_back(Savings_Account {}); 
    sav_accounts.push_back(Savings_Account {"Superman"} ); 
    sav_accounts.push_back(Savings_Account {"Batman", 2000});
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0}); 
    
    display(sav_accounts); 
    deposit(sav_accounts, 1000); 
    withdraw(sav_accounts, 2000); 
    
    //Checking
    vector<Checking_Account> check_accounts; 
    check_accounts.push_back(Checking_Account {}); 
    check_accounts.push_back(Checking_Account {"A"}); 
    check_accounts.push_back(Checking_Account {"B", 2000}); 
    check_accounts.push_back(Checking_Account {"C", 5000}); 
    
    display(check_accounts); 
    deposit(check_accounts, 1000); 
    withdraw(check_accounts, 2000); 
    
    //Trust
    vector<Trust_Account> trust_accounts; 
    trust_accounts.push_back(Trust_Account {}); 
    trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0}); 
    trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0}); 
    trust_accounts.push_back(Trust_Account {"Aramis", 30000}); 
    
    display(trust_accounts); 
    deposit(trust_accounts, 1000); 
    withdraw(trust_accounts, 3000); 
    
    for(int i = 1; i <= 5; i++)
        withdraw(trust_accounts, 1000); 
    
     */
    return 0; 
}