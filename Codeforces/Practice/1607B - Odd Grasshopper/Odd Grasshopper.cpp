#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll x, n;
    cin >> x >> n;
    if (n % 4 == 0) {
        cout << x << endl;
        return;
    }
    if (x % 2 == 0) {
        if (n % 4 == 1) {
            cout << x - n << endl;
        } else if (n % 4 == 2) {
            cout << x + 1 << endl;
        } else if (n % 4 == 3) {
            cout << x + n + 1 << endl;
        }
    } else {
        if (n % 4 == 1) {
            cout << x + n << endl;
        } else if (n % 4 == 2) {
            cout << x - 1 << endl;
        } else if (n % 4 == 3) {
            cout << x - n - 1 << endl;
        }
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}