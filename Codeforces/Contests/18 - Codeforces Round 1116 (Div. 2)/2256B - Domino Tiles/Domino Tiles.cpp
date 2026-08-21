#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    string s;
    cin >> n >> s;
    
    ll res = 0;

    // even
    ll ways_even = 0;

    // start 0
    bool valid_0 = true;
    for (ll i=0; i<n; i+=2) {
        char exp = ((i / 2) % 2 == 0) ? '0' : '1';
        if (s[i] != '?' && s[i] != exp) {
            valid_0 = false;
            break;
        }
    }
    if (valid_0) ways_even++;

    // start 1
    bool valid_1 = true;
    for (ll i=0; i<n; i+=2) {
        char exp = ((i / 2) % 2 == 0) ? '1' : '0';
        if (s[i] != '?' && s[i] != exp) {
            valid_1 = false;
            break;
        }
    }
    if (valid_1) ways_even++;

    // odd
    ll ways_odd = 0;

    // start 0
    valid_0 = true;
    for (ll i=1; i<n; i+=2) {
        char exp = ((i / 2) % 2 == 0) ? '0' : '1';
        if (s[i] != '?' && s[i] != exp) {
            valid_0 = false;
            break;
        }
    }
    if (valid_0) ways_odd++;

    // start 1
    valid_1 = true;
    for (ll i=1; i<n; i+=2) {
        char exp = ((i / 2) % 2 == 0) ? '1' : '0';
        if (s[i] != '?' && s[i] != exp) {
            valid_1 = false;
            break;
        }
    }
    if (valid_1) ways_odd++;

    cout << ways_even * ways_odd << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}