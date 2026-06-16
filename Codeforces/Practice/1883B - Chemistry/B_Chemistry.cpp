#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    string s;
    unordered_map<char, ll> freq;
    cin >> n >> k >> s;
    for (ll i=0; i<n; i++) {
        freq[s[i]]++;
    }
    ll reduction = 0;
    for (auto f : freq) {
        if (f.second % 2 == 1) {
            reduction++;
        }
    }
    if (reduction <= k+1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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