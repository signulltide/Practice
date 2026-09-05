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

#define rep2(i, a, b) for (ll i=a; i<b; i+=2)
#define rep(i, a, b) for (ll i=a; i<b; i++)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void Solve() {
    ll n;
    in(n);
    vector<ll> arr(n), sorted(n);
    vin(arr);
    ll gcd_e = arr[0], gcd_o = arr[1];
    rep2(i, 2, n) {
        gcd_e = __gcd(gcd_e, arr[i]);
    }
    rep2(i, 3, n) {
        gcd_o = __gcd(gcd_o, arr[i]);
    }

    if (gcd_e > 1) {
        
        bool flag = true;
        rep(j, 0, n - 1) {
            if ((arr[j] % gcd_e == 0 && arr[j+1] % gcd_e == 0) || (arr[j] % gcd_e != 0 && arr[j+1] % gcd_e != 0)) {
                //out(arr[j] % i, arr[j+1] % i);
                flag = false;
                break;
            }
        }
        if (flag) {
            out(gcd_e);
            return;
        }

    }

    if (gcd_o > 1) {
        
        bool flag = true;
        rep(j, 0, n - 1) {
            if ((arr[j] % gcd_o == 0 && arr[j+1] % gcd_o == 0) || (arr[j] % gcd_o != 0 && arr[j+1] % gcd_o != 0)) {
                //out(arr[j] % i, arr[j+1] % i);
                flag = false;
                break;
            }
        }
        if (flag) {
            out(gcd_o);
            return;
        }

    }

    out(0);

    return;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}