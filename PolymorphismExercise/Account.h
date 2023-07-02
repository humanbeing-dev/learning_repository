#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include "I_Printable.h"

class Account : public I_Printable {
private:
    static constexpr const char *def_name = "Unnamed Account"; // pointer to char is a c style string.
    static constexpr double def_balance = 0.0;
public:
    std::string name;
    double balance;
public:
    virtual void print(std::ostream &os) const override;
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    void operator+=(double amount);
    void operator-=(double amount);
    Account(std::string name = def_name, double balance = def_balance);
    // Account(std::string name = "Unnamed account" , double balance = 0.0);
    double get_balance() const;
    virtual ~Account () = default;
};

#endif // ACCOUNT_H
