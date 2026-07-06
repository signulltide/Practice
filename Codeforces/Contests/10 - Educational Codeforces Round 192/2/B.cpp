#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll n;
vector<ll> a;

bool Branch(ll start) {
    vector<ll> count(4, 0);
    for (ll i=start; i<n; i++) {
        count[a[i]]++;
        if (count[1] + count[2] >= count[3] && i < n-1) {
            return true;
        }
    }
    return false;
}

void Solve() {
    cin >> n;
    a.resize(n);
    vin(a);
    vector<ll> count(4, 0);
    for (ll i=0; i<n; i++) {
        count[a[i]]++;
        if (count[1] >= count[2] + count[3]) {
            if (Branch(i+1)) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}