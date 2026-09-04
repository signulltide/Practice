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

#define SIZE 2023

vector<ll> ans;

void Solve() {
    ll n;
    cin >> n;
    cout << ans[n-1] << endl;
}

int main() {
    fastIO;

    vector<vector<ll>> arr(SIZE, vector<ll>(SIZE, 0));
    ll count = 1;
    for (ll i=0; i<SIZE; i++) {
        for (ll j=0; j<=i; j++) {
            ll curr = pow(count, 2);
            ll left = 0, up = 0, diag = 0;
            if (i-j-1 >= 0 && j-1 >= 0) {
                diag = arr[i-j-1][j-1]; 
            }
            if (i-j-1 >= 0) {
                up = arr[i-j-1][j]; 
            }
            if (j-1 >= 0) {
                left = arr[i-j][j-1]; 
            }
            arr[i-j][j] = up + left + curr - diag;
            ans.push_back(arr[i-j][j]);
            count++;
        }
    }

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}