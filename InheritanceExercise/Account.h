#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <vector>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    static constexpr const char *def_name = "Unnamed Account"; // pointer to char is a c style string.
    static constexpr double def_balance = 0.0;
public:
    std::string name;
    double balance;
public:
    void operator+=(double amount);
    void operator-=(double amount);
    Account(std::string name = def_name, double balance = def_balance);
    // Account(std::string name = "Unnamed account" , double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

#endif // ACCOUNT_H
