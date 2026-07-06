#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

int main() {
    fastIO;

    ll n, d;
    cin >> n >> d;
    vector<ll> p(n);
    vin(p);
    sort(p.begin(), p.end());
    ll l = -1, r = n-1;
    ll size = 1;
    ll res = 0;
    while (l < r) {
        if (p[r] * size <= d && l < r) {
            size++;
            l++;
        } else {
            res++;
            r--;
            size = 1;
        }
    }
    cout << res << endl;

    return 0;
}