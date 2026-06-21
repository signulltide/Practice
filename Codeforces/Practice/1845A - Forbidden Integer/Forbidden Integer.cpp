#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    if (x == 1) {
        if (k > 2) {
            cout << "YES\n" << n/2 << endl;
            for (ll i=0; i<n/2-1; i++) {
                cout << "2 ";
            }
            if (n%2==0) {
                cout << "2\n";
            } else {
                cout << "3\n";
            }
        } else if (k > 1) {
            if (n%2==0) {
                cout << "YES\n" << n/2 << endl;
                for (ll i=0; i<n/2; i++) {
                    cout << "2 ";
                }
                cout << endl;
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "YES\n" << n << endl;
        for (ll i=0; i<n; i++) {
            cout << "1 ";
        }
        cout << endl;
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}