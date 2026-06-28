#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n), b(n), sa(n), sb(n);
    vin(a); vin(b);
    sa = a; sb = b;
    ll noOper = 0, yesOper = c;
    bool skipNo = false, skipYes = false;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    for (ll i=0; i<n; i++) {

        if (sa[i] < sb[i]) {
            skipYes = true;
        }
        yesOper += sa[i] - sb[i];

        if (a[i] < b[i]) {
            skipNo = true;
        }
        noOper += a[i] - b[i];
    }

    if (noOper < yesOper && !skipNo) {
        cout << noOper << endl;
    } else if (!skipYes) {
        cout << yesOper << endl;
    } else {
        cout << "-1\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}