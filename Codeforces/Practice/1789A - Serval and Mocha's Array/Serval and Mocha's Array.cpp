#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll gcd(ll a, ll b) {    
    return b == 0 ? a : gcd(b, a % b);
}

void Solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vin(a);
    for (ll i=0; i<n; i++) {
        for (ll j=i+1; j<n; j++) {
            if (gcd(a[i], a[j]) <= 2) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}