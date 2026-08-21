#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> b(n);
    vin(b);
    unordered_map<ll, ll> freq;
    for (ll i=0; i<n; i++) {
        freq[b[i]]++;
        if (freq[b[i]] > 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}