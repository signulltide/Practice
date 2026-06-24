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
    ll nCount = 0, pCount = 0, res = 0;
    for (ll i=0; i<n; i++) {
        if (arr[i] == -1) {
            nCount++;
        } else {
            pCount++;
        }
    }
    ll diff = max(0ll, (nCount - pCount + 1) / 2);
    cout << diff + ((nCount - diff) % 2) << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}