#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int& f1(int& a);
const int& f2(int& a);

int main(int argc, char const* argv[])
{
    /* code */
    return 0;
}




int& f1(int& a) {
    a++;
    return a;
}

const int& f2(int& a) {
    a++;
    return a;
}