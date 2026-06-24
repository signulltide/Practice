#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        cout << "YES\n";
    } else {
        if (k % 2 == 0) {
            cout << "NO\n";
        } else if (k <= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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