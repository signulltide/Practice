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
    vector<ll> arr(n), res;
    vin(arr);
    res.push_back(arr[0]);
    for (ll i=1; i<n; i++) {
        if (arr[i] >= arr[i-1]) {
            res.push_back(arr[i]);
        } else {
            res.push_back(arr[i]); res.push_back(arr[i]);
        }
    }
    cout << res.size() << endl;
    vout(res);
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