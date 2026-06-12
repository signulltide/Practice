#include <iostream>
#include <string>
using namespace std;

#define ll long long

void Solve() {
    string s;
    ll n, k;
    cin >> n >> k >> s;
    for (ll i=0; i<n-k; i++) {
        if (s[i] == '1') {
            s[i] = '0';
            if (i+k >= n) continue;
            if (s[i+k] == '1') {
                s[i+k] = '0';
            } else {
                s[i+k] = '1';
            }
        }
    }
    for (ll i=0; i<n; i++) {
        if (s[i] == '1') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}