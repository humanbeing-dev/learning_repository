#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr int def_withdraw_times = 0;
protected:
    int withdraw_times;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    void operator+=(double amount);
    void operator-=(double amount);
    virtual ~Trust_Account () {}
    virtual void print(std::ostream &os) const override;
};

#endif // TRUST_ACCOUNT_H