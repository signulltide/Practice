#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k, temp;
    cin >> n >> k;
    vector<pair<ll, ll>> monsters; // index, hp
    for (ll i=0; i<n; i++) {
        cin >> temp;
        ll rem = temp%k;
        if (rem == 0) rem = k;
        monsters.push_back({i+1, rem});
    }
    sort(monsters.begin(), monsters.end(), [k](const pair<ll, ll> &a, const pair<ll, ll> &b){
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    for (auto &[i, hp] : monsters) {
        cout << i << " ";
    }
    cout << endl;
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