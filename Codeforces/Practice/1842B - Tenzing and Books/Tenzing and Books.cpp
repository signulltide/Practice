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

#define in(...) [&](auto&... args){ (cin >> ... >> args); }(__VA_ARGS__)
#define out(...) [&](auto&&... args){ int n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void Solve() {
    ll n, x;
    in(n, x);
    vector<ll> a(n), b(n), c(n);
    vector<ll> pa(n, 0), pb(n, 0), pc(n, 0);
    vin(a, b, c);
    pa[0] = a[0]; pb[0] = b[0]; pc[0] = c[0];
    ll ba = 0, bb = 0, bc = 0;
    bool fa = false, fb = false, fc = false;
    if (((x | pa[0]) != x) && !fa) {
        ba = 0; fa = true;
    }
    if (((x | pb[0]) != x) && !fb) {
        bb = 0; fb = true;
    }
    if (((x | pc[0]) != x) && !fc) {
        bc = 0; fc = true;
    }
    for (ll i=1; i<n; i++) {
        pa[i] = pa[i-1] | a[i];
        pb[i] = pb[i-1] | b[i];
        pc[i] = pc[i-1] | c[i];
        if (((x | pa[i]) != x) && !fa) {
            ba = pa[i-1]; fa = true;
        }
        if (((x | pb[i]) != x) && !fb) {
            bb = pb[i-1]; fb = true;
        }
        if (((x | pc[i]) != x) && !fc) {
            bc = pc[i-1]; fc = true;
        }
    }
    if (!fa) {
        ba = pa[n-1]; fa = true;
    }
    if (!fb) {
        bb = pb[n-1]; fb = true;
    }
    if (!fc) {
        bc = pc[n-1]; fc = true;
    }
    if (((ba | bb) | bc) == x) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}