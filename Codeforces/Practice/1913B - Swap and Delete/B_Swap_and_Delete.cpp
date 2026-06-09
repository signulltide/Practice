#include <iostream>
#include <string>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        string s;
        cin >> s;
        ll count0 = 0, count1 = 0, cost = 0;
        for (ll i=0; i<s.length(); i++) {
            if (s[i] == '0') {
                count0++;
            } else {
                count1++;
            }
        }
        for (ll i=0; i<s.length(); i++) {
            if (s[i] == '0' && count1 > 0) {
                count1--;
            } else if (s[i] == '1' && count0 > 0) {
                count0--;
            } else {
                cost = s.length() - i;
                break;
            }
        }
        cout << cost << '\n';
    }
}