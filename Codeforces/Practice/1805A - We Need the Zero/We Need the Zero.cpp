#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vin(arr);
    ll total_xor = arr[0];
    for (ll i=1; i<n; i++) {
        total_xor ^= arr[i];
    }
    if (n % 2 == 0 && total_xor != 0) {
        cout << "-1\n";
    } else {
        cout << total_xor << endl;
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}