#include <iostream>

using namespace std;

const int SEC_PER_MIN = 60;
const int MIN_PER_HOUR = 60;
const int HOUR_PER_DAY = 24;

int main() {
    long long seconds;
    int days, hours, minutes;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    days = seconds / (SEC_PER_MIN * MIN_PER_HOUR * HOUR_PER_DAY);
    seconds -= days * (SEC_PER_MIN * MIN_PER_HOUR * HOUR_PER_DAY);
    hours = seconds / (SEC_PER_MIN * MIN_PER_HOUR);
    seconds -= hours * (SEC_PER_MIN * MIN_PER_HOUR);
    minutes = seconds / SEC_PER_MIN;
    seconds -= minutes * SEC_PER_MIN;
    cout << seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds.";
    return 0;
}