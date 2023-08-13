#include "BankAccount.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    BankAccount ba("Nik", "0001", 1200);
    ba.print_info();
    ba.init_account("Nik Swit", "", 1500);
    ba.print_info();
    ba.save(223.5);
    ba.print_info();
    return 0;
}