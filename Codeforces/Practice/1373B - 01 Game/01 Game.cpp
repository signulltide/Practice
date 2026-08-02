#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    string s;
    cin >> s;
    ll c0 = 0, c1 = 0;
    for (ll i=0; i<s.length(); i++) {
        if (s[i] == '0') {c0++;} else {c1++;}
    }
    if (min(c0, c1) % 2 == 1) {
        cout << "DA\n";
    } else {
        cout << "NET\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}