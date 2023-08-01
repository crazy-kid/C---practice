/*
该程序使用gcc编译会报错，因为gcc不会自动寻找函数库
应当用g++编译
*/

#include <iostream>

using namespace std;

int main() {
    cout << "Name: " << "周瀚" << endl;
    cout << "Address: " << "温州" << endl;
    return 0;
}