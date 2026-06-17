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
    ll least = (k*(k+1))/2, most = ((n*(n+1))/2) - (((n-k)*((n-k)+1))/2);
    if (least <= x && x <= most) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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