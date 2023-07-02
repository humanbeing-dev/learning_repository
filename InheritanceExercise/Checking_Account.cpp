#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name,balance} { }
    
 
// Withdraw:
//    A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
//    Every withdrawal transaction will be assessed this flat fee.
   
bool Checking_Account::withdraw(double amount) {
    amount += def_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << ": " << account.balance << ", Withdrawal flat fee: " << account.def_fee << "$]";
    return os;
}

void Checking_Account::operator+=(double amount) {
    std::cout << "\n === Depositing to " << name << " ============================" << std::endl;
        if (deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << name << std::endl;
        }
        else
            std::cout << "Failed Deposit of " << amount << " to " << name << std::endl;
    }
    
void Checking_Account::operator-=(double amount) {
    std::cout << "\n === Withdrawing from " << name << " ============================" << std::endl;
        if (withdraw(amount)) {
            std::cout << "Withdrawed " << amount << " from " << name << std::endl;
        }
        else
            std::cout << "Failed to Withdraw " << amount << " from " << name << std::endl;
    }


