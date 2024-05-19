#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    // Handle special cases: 1 and negative numbers are not prime
    if (num <= 1) {
        return false;
    }

    // Efficiently check divisibility only up to the square root of num
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int lowerBound = 1, upperBound = 100;

    cout << "Prime numbers between " << lowerBound << " and " << upperBound << ":\n";
    for (int num = lowerBound; num <= upperBound; num++) {
        if (isPrime(num)) {
            cout << num << " ";
        }
    }

    cout << "\n"; // Add a newline for better readability

    // Example of checking a user-given number
    int userNum;
    cout << "Enter a number to check if it's prime: ";
    cin >> userNum;

    if (isPrime(userNum)) {
        cout << userNum << " is a prime number.\n";
    } else {
        cout << userNum << " is not a prime number.\n";
    }

    return 0;
}
