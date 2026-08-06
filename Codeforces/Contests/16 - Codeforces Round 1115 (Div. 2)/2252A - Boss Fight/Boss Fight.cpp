#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, total_damage = 0;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> freq;
    vin(arr);
    for (ll a : arr) {
        freq[a]++;
        total_damage += a;
    }
    ll most_frequent = 0, most_frequent_damage = 0;
    for (auto &[a, f] : freq) {
        if (f >= most_frequent) {
            most_frequent = f;
            most_frequent_damage = a;
        }
    }
    ll seps = n - most_frequent;
    if (most_frequent <= seps + 2) {
        cout << total_damage << endl;
    } else {
        cout << total_damage - (most_frequent_damage * most_frequent) + (most_frequent_damage * (seps + 2)) << endl;
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}