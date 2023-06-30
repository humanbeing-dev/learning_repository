#include "Account.h"

Account::Account(std::string name, double balance)
    : name{name}, balance{balance} { }

bool Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount){
    if (balance-amount >=0) {
        balance -= amount;
        return true;
    } else
        return false;
}

double Account::get_balance() const {
    return balance;
}
    
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}

void Account::operator+=(double amount) {
    std::cout << "\n === Depositing to " << name << " ============================" << std::endl;
        if (deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << name << std::endl;
        }
        else
            std::cout << "Failed Deposit of " << amount << " to " << name << std::endl;
    }
    
void Account::operator-=(double amount) {
    std::cout << "\n === Withdrawing from " << name << " ============================" << std::endl;
        if (withdraw(amount)) {
            std::cout << "Withdrawed " << amount << " from " << name << std::endl;
        }
        else
            std::cout << "Failed to Withdraw " << amount << " from " << name << std::endl;
    }