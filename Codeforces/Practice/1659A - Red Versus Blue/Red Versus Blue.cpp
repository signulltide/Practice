#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, r, b;
    ll rr = r, rb = b;
    cin >> n >> r >> b;
    ll once = r / (b + 1);
    ll rem = r % (b + 1);
    for (ll i=0; i<b+1; i++) {
        for (ll j=0; j<once; j++) {
            cout << "R";
        }
        if (rem > 0) {
            cout << "R";
            rem--;
        }

        // Add 'B' except for the last segment
        if (i < b) {
            cout << "B";
        }
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