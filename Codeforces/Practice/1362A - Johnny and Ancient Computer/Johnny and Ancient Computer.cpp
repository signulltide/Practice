#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    ll c = b / a;

    if (c > 0 && (c & (c - 1)) != 0 || b % a != 0) {
        cout << "-1\n";
        return;
    }

    ll steps = log2(c);
    if (steps % 3 == 0) {
        cout << steps / 3 << endl;
    } else {
        cout << (steps / 3) + 1 << endl;
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}