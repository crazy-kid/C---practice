#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

#include <string>

using namespace std;

class BankAccount {
private:
    string fullname;
    string accid;
    double balance;

public:
    BankAccount();
    BankAccount(const string name, const string id, double bal);
    ~BankAccount();
    void init_account(const string name, const string id, double bal);
    void print_info() const;
    void save(double cash);
    void withdraw(double cash);
};

#endif