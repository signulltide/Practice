#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    ll p = 1;
    while (p*2 <= n-1) {
        p *= 2;
    }
    for (ll i=n-1; i>=p; --i) {
        cout << i << " ";
    }
    for (ll i=0; i<p; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}