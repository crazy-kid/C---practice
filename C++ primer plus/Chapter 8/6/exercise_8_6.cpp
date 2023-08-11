#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
T maxn(T[], int);

template<> char* maxn<char*>(char* [], int);

int main() {
    int arr[5] = { 1, 2, 5, 4, 3 };
    double arr_d[5] = { 19.6, 13, 19.8, 100.8, 98.4 };
    string ss[] = { "Hello", "Hello World!" };

    cout << "The Max Element of int array: " << maxn(arr, 5) << endl;
    cout << "The Max Element of double array: " << maxn(arr_d, 5) << endl;
    cout << "The Max Element of string array: " << maxn(ss, 2) << endl;
    return 0;
}

template<typename T>
T maxn(T array[], int n) {
    T max = array[0];
    for (int i = 0;i < n;i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

template<>
char* maxn<char*>(char** array, int n) {
    char* ret = array[0];
    for (int i = 0;i < n;i++) {
        if (strlen(ret) < strlen(array[0]))
            ret = array[i];
    }
    return ret;
}