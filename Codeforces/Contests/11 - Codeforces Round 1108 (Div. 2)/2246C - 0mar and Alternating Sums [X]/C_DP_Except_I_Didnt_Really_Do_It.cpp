#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll n, c = 0;
vector<ll> arr;

void Solve() {
    cin >> n;
    arr.resize(n);
    vin(arr);
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2)));
    for (ll i=0; i<n; i++) {
        //fuckkkkkk
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}