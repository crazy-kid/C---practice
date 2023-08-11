#include <iostream>

using namespace std;

template <typename T>
T max5(T*);

int main() {
    int intArray[5] = { 1, 2, 3, 4, 5 };
    double doubleArray[5] = { 3.14, 2.71, 9.8, 2.4, 2.1 };
    cout << max5(intArray) << endl;
    cout << max5(doubleArray) << endl;
    return 0;
}


template <typename T>
T max5(T* array) {
    T max = *array;
    for (int i = 0;i < 5;i++)
        if (*(array + i) > max)
            max = *(array + i);
    return max;
}