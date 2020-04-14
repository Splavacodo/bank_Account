#include <iostream> 
#include <memory>
#include "Account.h" 
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std; 

int main() {
    std::vector<std::shared_ptr<Account>> accounts{}; 
    run_program(accounts); 
    return 0; 
}