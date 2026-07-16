#include <iostream>
#include <string>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll res = 0;
    if (k > n/2) {
        cout << "-1\n";
        return;
    }
    for (ll i=0; i<k; i++) {
        if (s[i] == 'L') res++;
        if (s[n-i-1] == 'R') res++;
    }
    cout << res << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}