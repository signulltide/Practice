#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k, a, b, x, y;
    cin >> n >> k >> a >> b;
    a--; b--;
    vector<pair<ll, ll>> city(n);
    for (ll i=0; i<n; i++) {
        cin >> city[i].first >> city[i].second;
    }
    ll ans = abs(city[b].first - city[a].first) + abs(city[b].second - city[a].second);
    ll closest_a = ans, closest_b = ans;
    for (ll i=0; i<k; i++) {
        ll dist_a = abs(city[i].first - city[a].first) + abs(city[i].second - city[a].second);
        closest_a = min(closest_a, dist_a);
        ll dist_b = abs(city[i].first - city[b].first) + abs(city[i].second - city[b].second);
        closest_b = min(closest_b, dist_b);
    }
    cout << min(ans, closest_a + closest_b) << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}