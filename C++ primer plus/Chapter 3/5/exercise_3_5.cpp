#include <iostream>

using namespace std;

int main() {
    long long globalAmount, americanAmount;
    double populationPercent;
    cout << "Enter the world's population: ";
    cin >> globalAmount;
    cout << "Enter the population of US";
    cin >> americanAmount;
    populationPercent = 100 * (double)americanAmount / (double)globalAmount;
    cout << "The population of the US is " << populationPercent << "% of the world population.";
    return 0;
}