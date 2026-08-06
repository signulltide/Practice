#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
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
    char last = s[0];
    ll del_0 = 0, del_1 = 0, edge_0 = 0, edge_1 = 0;
    for (ll i=1; i<n; i++) {
        if (s[i] != last) {
            last = s[i];
        } else {
            if (s[i] == '0') {
                del_0++;
            } else {
                del_1++;
            }
        }
    }
    if (abs(del_0 - del_1) > 1) {
        if (del_1 > del_0) {
            ll rem_1 = del_1 - del_0 - 1;
            ll edge_0 = 0;
            if (s[0] == '0') edge_0++;
            if (s[n-1] == '0') edge_0++;

            if (edge_0 >= rem_1) {
                cout << del_0 + del_1 + (rem_1) << endl;
                return;
            } else {
                cout << "-1\n";
                return;
            }
        } else {
            ll rem_0 = del_0 - del_1 - 1;
            ll edge_1 = 0;
            if (s[0] == '1') edge_1++;
            if (s[n-1] == '1') edge_1++;

            if (edge_1 >= rem_0) {
                cout << del_0 + del_1 + (rem_0) << endl;
                return;
            } else {
                cout << "-1\n";
                return;
            }
        }
    } else {
        cout << del_0 + del_1 << endl;
        return;
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}