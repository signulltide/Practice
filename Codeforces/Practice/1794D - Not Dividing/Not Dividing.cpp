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
    for (ll i=0; i<n; i++) {
        if (arr[i] == 1) arr[i]++;
    }
    for (ll i=0; i<n-1; i++) {
        if (arr[i+1] % arr[i] == 0) {
            arr[i+1]++;
        }
    }
    vout(arr);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}