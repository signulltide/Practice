#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll k, temp, count = 0;
    bool res = false;
    cin >> k;
    for (ll i=0; i<k; i++) {
        cin >> temp;
        if (temp > 2) {
            res = true;
        }
        if (temp == 2) {
            count++;
            if (count == 2) {
                res = true;
            }
        }
    }
    if (res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}