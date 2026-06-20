#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, temp;
    cin >> n;
    vector<ll> ducks(n), final(n), sorted(n);
    vin(ducks);
    vin(final);
    sorted = ducks;

    sort(sorted.begin(), sorted.end());
    for (ll i=0; i<n; i++) {
        if (sorted[i] > final[i]) {
            cout << "-1\n";
            return;
        }
    }

    vector<ll> p(n);
    vector<bool> used(n, false);
    for (ll j=0; j<n; j++) {
        ll best = -1;
        for (ll i=0; i<n; i++) {
            if (!used[i] && ducks[i] <= final[j]) {
                best = i;
                break;
            }
        }
        used[best] = true;
        p[best] = j;
    }

    ll inv = 0;
    for (ll i=0; i<n; i++) {
        for (ll j=i+1; j<n; j++) {
            if (p[i] > p[j]) {
                inv++;
            }
        }
    }
    cout << inv << endl;
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