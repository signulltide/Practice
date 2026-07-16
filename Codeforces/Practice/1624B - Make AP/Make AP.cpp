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
    ll ta, tb, tc;
    ta = b + (b - c);
    tb = a + ((c - a) / 2);
    tc = b + (b - a);
    // cout << a << " " << b << " " << c << endl;
    // cout << ta << " " << tb << " " << tc << endl;
    if ((ta % a == 0 && ta >= a) || (tb % b == 0 && 2*tb == a + c) || (tc % c == 0 && tc >= c)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}