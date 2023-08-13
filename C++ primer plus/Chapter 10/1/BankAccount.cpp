#include "BankAccount.h"
#include <string>
#include <iostream>

using namespace std;
// using namespace BankAccount;

BankAccount::BankAccount() {}

BankAccount::BankAccount(const string name, const string id, double bal) {
    fullname = name;
    accid = id;
    balance = bal;
}

BankAccount::~BankAccount() {}

void BankAccount::init_account(const string name, const string id, double bal) {
    fullname = name;
    accid = id;
    balance = bal;
}

void BankAccount::print_info() const {
    cout << "fullname: " << fullname << endl;
    cout << "accid: " << accid << endl;
    cout << "balance: " << balance << endl;
    cout << endl;
}

void BankAccount::save(double cash) {
    if (cash > 0)
        balance += cash;
    else
        cout << "ERROR: invalid cash number" << endl;
}

void BankAccount::withdraw(double cash) {
    if (cash >= balance)
        balance -= cash;
    else
        cout << "ERROR: invalid cash number" << endl;
}