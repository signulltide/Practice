#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, ones = 0, zeroes = 0, res = 0;
    cin >> n;
    vector<ll> arr(n);
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {ones++;} else if (arr[i] == 0) {zeroes++;}
    }
    res = pow(2, zeroes) * ones;
    cout << res << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}