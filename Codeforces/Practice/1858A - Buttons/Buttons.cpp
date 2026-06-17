#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (c%2 == 1) {
        if (b > a) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    } else {
        if (a > b) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
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