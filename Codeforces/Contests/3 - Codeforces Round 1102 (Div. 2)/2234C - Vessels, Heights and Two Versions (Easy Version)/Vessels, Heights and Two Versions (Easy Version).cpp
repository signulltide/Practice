#include <iostream>
#include <vector>
using namespace std;

#define ll long long

void Solve() {
    ll n;
    cin >> n;
    vector<ll> bridge(n);
    for (ll i=0; i<n; i++) {
        cin >> bridge[i];
    }
    for (ll empty=0; empty<n; empty++) {
        vector<ll> cw(n, 0), ccw(n, 0);

        ll curr = 0;

        for (ll i=1; i<n; i++) {
            ll edge = (empty + i - 1) % n;
            ll vessel = (empty + i) % n;

            curr = max(curr, bridge[edge]);
            cw[vessel] = curr;
        }

        curr = 0;

        for (ll i=1; i<n; i++) {
            ll vessel = (empty - i + n) % n;
            ll edge = vessel;

            curr = max(curr, bridge[edge]);
            ccw[vessel] = curr;
        }

        ll total = 0;

        for (ll j=0; j<n; j++) {
            if (j == empty) continue;
            total += min(cw[j], ccw[j]);
        }

        cout << total << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}