#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream read;
    int count = 0;
    read.open("exercise_6_8_file");
    char c;
    if (!read.is_open()) {
        cout << "ERROR: open fail" << endl;
        return 0;
    }
    /*
    无法用下面的方法检测EOF, 因为EOF不在ASCII码中，以整型读取时得到-1；
    do {
        read >> c;
        count++;
        cout << c;
    } while (c != EOF);
    */
    while (!read.eof()) {
        read >> c;
        count++;
    }
    cout << count << endl;
    return 0;
}