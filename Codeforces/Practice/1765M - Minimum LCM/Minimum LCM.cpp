#include <iostream>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n/2 << " " << n/2 << endl;
    } else {
        for (ll i=2; i*i<=n; i++) {
            if (n % i == 0) {
                cout << n/i << " " << n-(n/i) << endl;
                return;
            }
        }
        cout << "1 " << n-1 << endl;
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}