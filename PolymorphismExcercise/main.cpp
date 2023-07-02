// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "I_Printable.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
    
    Checking_Account c;
    cout << c << std::endl;
    
    Savings_Account s {"Frank", 5000, 2.6};
    cout << s << endl;
    
    s.deposit(10000);
    cout << s << endl;
    s.withdraw(10000);
    cout << s << endl;
    Account *ptr = new Trust_Account{"Leo", 10000, 2.6};
    cout << *ptr << endl;
    
    Account *p1 = new Checking_Account("Larry",10000);
    Account *p2 = new Savings_Account("Moe", 1000);
    Account *p3 = new Trust_Account("Curly");
    
    std::vector<Account *> accounts {p1,p2,p3};
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    display(accounts);
    
    return 0;
}

