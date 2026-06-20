#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define ll long long

void Solve() {
    ll a, b, x;
    ll ta, tb;
    vector<ll> da, db;
    cin >> a >> b >> x;
    ta = a; tb = b;
    while (ta > 0) {
        da.push_back(ta);
        ta /= x;
    }
    while (tb > 0) {
        db.push_back(tb);
        tb /= x;
    }
    da.push_back(0); db.push_back(0);
    ll res = LLONG_MAX;
    for (ll i=0; i<da.size(); i++) {
        for (ll j=0; j<db.size(); j++) {
            res = min(res, i + j + abs(da[i] - db[j]));
        }
    }
    cout << res << '\n';
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