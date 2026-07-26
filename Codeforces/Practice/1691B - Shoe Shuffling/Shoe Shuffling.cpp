#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n), pos(n);
    vin(arr);
    map<ll, ll> freq;
    for (ll a : arr) {
        freq[a]++;
    }
    for (auto &[a, f] : freq) {
        if (f == 1) {
            cout << "-1\n";
            return;
        }
    }
    for (ll i=0; i<n; i++) {
        pos[i] = i+1;
    }
    ll l = 0, r = 0;
    while (r < n) {
        if (arr[r] != arr[l]) {
            rotate(pos.begin() + l, pos.begin() + l + 1, pos.begin() + r);
            l = r;
        } else {
            r++;
        }
    }
    rotate(pos.begin() + l, pos.begin() + l + 1, pos.begin() + r);
    vout(pos);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}