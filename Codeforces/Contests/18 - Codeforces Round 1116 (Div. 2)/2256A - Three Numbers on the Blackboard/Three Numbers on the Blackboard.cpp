#include <iostream>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll most = max(max(a, b), c), least = min(min(a, b), c);
    ll att = a + b + c - most;
    cout << min(att - least, most - least) << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}