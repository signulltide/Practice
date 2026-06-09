#include <iostream>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll testCount, boxCount, maxLength, curr;
    cin >> testCount;
    for (ll i=0; i<testCount; i++) {
        ll prev = 0;
        cin >> boxCount >> maxLength;
        bool flag = true;
        for (ll j=0; j<boxCount; j++) {
            cin >> curr;
            if (curr < prev) flag = false;
            prev = curr;
        }
        if (maxLength > 1) flag = true;
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}