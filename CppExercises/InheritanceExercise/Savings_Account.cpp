#include "Savings_Account.h"


Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account {name,balance}, int_rate{int_rate} { }
    
 
// Deposit:
//    Amount supplied to deposit will be incremented by (amount * int_rate/100)
//    and then the updated amount will be deposited
   
bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "[Savings Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

void Savings_Account::operator+=(double amount) {
    std::cout << "\n === Depositing to " << name << " ============================" << std::endl;
        if (deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << name << std::endl;
        }
        else
            std::cout << "Failed Deposit of " << amount << " to " << name << std::endl;
    }
    
void Savings_Account::operator-=(double amount) {
    std::cout << "\n === Withdrawing from " << name << " ============================" << std::endl;
        if (withdraw(amount)) {
            std::cout << "Withdrawed " << amount << " from " << name << std::endl;
        }
        else
            std::cout << "Failed to Withdraw " << amount << " from " << name << std::endl;
    }



