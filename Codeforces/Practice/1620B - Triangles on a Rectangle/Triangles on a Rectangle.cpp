#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll w, h;
    cin >> w >> h;

    ll k, dump;
    cin >> k;
    ll a, b;
    ll most = 0;
    for (ll i=0; i<k; i++) {
        if (i == 0) {
            cin >> a;
        } else if (i == k-1) {
            cin >> b;
        } else {
            cin >> dump;
        }
    }
    most = (b-a) * h;

    cin >> k;
    for (ll i=0; i<k; i++) {
        if (i == 0) {
            cin >> a;
        } else if (i == k-1) {
            cin >> b;
        } else {
            cin >> dump;
        }
    }
    most = max(most, (b-a) * h);

    cin >> k;
    for (ll i=0; i<k; i++) {
        if (i == 0) {
            cin >> a;
        } else if (i == k-1) {
            cin >> b;
        } else {
            cin >> dump;
        }
    }
    most = max(most, (b-a) * w);

    cin >> k;
    for (ll i=0; i<k; i++) {
        if (i == 0) {
            cin >> a;
        } else if (i == k-1) {
            cin >> b;
        } else {
            cin >> dump;
        }
    }
    most = max(most, (b-a) * w);

    cout << most << endl;
    
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}