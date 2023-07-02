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

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
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

void Checking_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Checking Account: " << name << ": " << balance << ", Withdrawal flat fee: " << this->def_fee << "$]";
}

