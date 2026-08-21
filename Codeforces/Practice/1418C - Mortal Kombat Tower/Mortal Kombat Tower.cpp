#include <iostream>
#include <vector>
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
    vector<ll> arr(n);
    vin(arr);
    ll skips = 0;
    if (arr[0] == 1) skips++;
    ll streak = 0;
    for (ll i=1; i<n; i++) {
        if (arr[i] == 1) {
            streak++;
        } else {
            skips += (streak/3);
            streak = 0;
        }
    }
    skips += (streak/3);
    cout << skips << endl;
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