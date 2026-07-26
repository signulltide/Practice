#include <iostream>
#include <math.h>
#include <string>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl


void Solve() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "0 0\n";
        return;
    }
    ll gcd = max(a, b) - min(a, b);
    cout << gcd << " " << min(b%gcd, gcd-b%gcd) << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}