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
    sort(arr.begin(), arr.end());
    if (arr[0] == arr[n-1]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << arr[n-1] << " ";
    for (ll i=0; i<n-1; i++) {
        cout << arr[i] << " ";
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