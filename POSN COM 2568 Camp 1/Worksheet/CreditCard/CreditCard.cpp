#include <iostream>
using namespace std;

int main() {
    string s;
    int sum = 0, x, i;
    cin >> s;
    for (i=s.length()-1; i>=0; i--) {
        if (i%2==0) {
            x = 2*(s[i]-'0');
            if (x >= 10) {
                sum += (x%10) + (x/10);
            } else {
                sum += x;
            }
        } else {
            x = s[i] - '0';
            sum += x;
        }
    }
    if (sum%10==0) {
        cout << "yes";
    } else {
        cout << "no";
    }
}
