#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;

    cout << "Enter a positive integer: ";
    cin >> num;

    if (isPrime(num))
        cout << num << " is a prime number";
    else
        cout << num << " is not a prime number";

    return 0;
}
