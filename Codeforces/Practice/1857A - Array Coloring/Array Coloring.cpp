#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, temp, oddCount = 0;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        if (temp % 2 == 1) {
            oddCount++;
        }
    }
    if (oddCount % 2 == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}