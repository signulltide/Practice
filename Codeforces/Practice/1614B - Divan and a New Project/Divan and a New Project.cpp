#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, temp;
    cin >> n;
    vector<pair<ll, ll>> arr; // times, id
    for (ll i=1; i<=n; i++) {
        cin >> temp;
        arr.push_back({temp, i});
    }
    sort(arr.rbegin(), arr.rend());
    vector<ll> res(n+1, 0);
    ll total = 0;
    ll curr = 1;
    for (auto &[times, i] : arr) {
        res[i] = curr;
        total += abs(curr) * times * 2;
        if (curr < 0) {
            curr--;
        }
        curr *= -1;
    }
    cout << total << endl;
    cout << "0 ";
    for (ll i=1; i<=n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}