#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b, c;
    vin(a);
    sort(a.begin(), a.end());
    ll firstGreater = a[0];
    for (ll i=0; i<n; i++) {
        if (a[i] > firstGreater) {
            c.push_back(a[i]);
        } else {
            b.push_back(a[i]);
        }
    }
    if (c.size() == 0) {
        cout << "-1\n";
    } else {
        cout << b.size() << " " << c.size() << endl;
        vout(b);
        vout(c);
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