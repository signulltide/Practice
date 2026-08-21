#include <iostream>
#include <string>
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
    ll l = 0, r = 0;
    for (char c : s) {
        if (c == '(') {
            l++;
        } else {
            if (l > 0) {
                l--;
            // } else {
            //     r++;
            }
        }
    }
    cout << l << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}