#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n*k);
    vin(arr);
    ll res = 0;
    ll diff = n-(n/2);
    if (n%2==0) diff++;
    for (ll i=1; i<=k; i++) {
        res += arr[n*k - (i*diff)];
    }
    cout << res << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}