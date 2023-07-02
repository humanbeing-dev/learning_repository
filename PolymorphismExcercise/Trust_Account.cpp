#include "Trust_Account.h"



Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name,balance,int_rate}, withdraw_times{def_withdraw_times}  { }
    
// Deposit
//      any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account
bool Trust_Account::deposit(double amount) {
    if (amount >= 5000.0)
        amount += 50.0;
    return Savings_Account::deposit(amount);
}

// Withdrawal
//      withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance

bool Trust_Account::withdraw(double amount) {
    if (withdraw_times < 3 && amount <= balance*2/10) {
        withdraw_times++;
        return Account::withdraw(amount);
    } else {
        return false;
    }
}


void Trust_Account::operator+=(double amount) {
    std::cout << "\n === Depositing to " << name << " ============================" << std::endl;
        if (deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << name << std::endl;
            
        }
        else
            std::cout << "Failed Deposit of " << amount << " to " << name << std::endl;
    }
    
void Trust_Account::operator-=(double amount) {
    std::cout << "\n === Withdrawing from " << name << " ============================" << std::endl;
        if (withdraw(amount)) {
            std::cout << "Withdrawed " << amount << " from " << name << std::endl;
        }
        else
            std::cout << "Failed to Withdraw " << amount << " from " << name << std::endl;
    }
    
void Trust_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust Account: " << name << ": " << balance << ", Withdrawals left: " << 3 - withdraw_times << "]";
}