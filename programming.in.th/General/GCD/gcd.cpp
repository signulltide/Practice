#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b % a == 0) {
        return a;
    } else {
        return gcd(b % a, a);
    }
}

int main() {
    int num1, num2, temp;
    cin >> num1 >> num2;
    if (num2 > num1) {
        temp = num2;
        num2 = num1;
        num1 = temp;
    }
    cout << gcd(num1, num2);
    return 0;
}