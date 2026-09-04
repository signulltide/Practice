#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define MOD1 1000000007
#define MOD2 998244353

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define ff first
#define ss second

#define in(...) [&](auto&... args){ (cin >> ... >> args); }(__VA_ARGS__)
#define out(...) [&](auto&&... args){ int n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

#define rep(i, a, b) for (ll i=a; i<b; i++)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void Solve() {
    ll n, c;
    in(n, c);
    vector<ll> arr(n);
    map<ll, ll> pos;
    vector<pair<ll, ll>> cost(n);
    vin(arr);
    rep(i, 0, n) {
        cost[i] = {min(arr[i] + i + 1, arr[i] + n - i), i};
    }
    sort(all(cost));
    vector<ll> pref(n, 0);
    pref[0] = cost[0].ff;
    rep(i, 0, n) {
        pos[cost[i].ss] = i;
        if (i == 0) continue;
        pref[i] = pref[i - 1] + cost[i].ff;
    }
    ll most = 0;
    rep(i, 0, n) {
        ll start_cost = arr[i] + i + 1;
        ll min_cost_i = min(arr[i] + i + 1, arr[i] + n - i);

        if (c >= start_cost) {
            ll rem = c - start_cost;
            
            auto it = upper_bound(pref.begin(), pref.end(), rem);
            
            if (pos[i] >= distance(pref.begin(), it)) {
                most = max(most, distance(pref.begin(), it) + 1);
            } else {
                auto it_new = upper_bound(pref.begin(), pref.end(), rem + min_cost_i);
                most = max(most, distance(pref.begin(), it_new));
            }
        }
    }

    out(most);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    };

    return 0;
}