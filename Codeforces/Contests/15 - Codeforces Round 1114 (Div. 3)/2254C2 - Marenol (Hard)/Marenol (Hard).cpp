#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    string a, b;
    cin >> n >> a >> b;
    
    ll res = 0;
    vector<ll> aEven, bEven;
    for (ll i=0; i<n; i+=2) {
        if (a[i] == '1') aEven.push_back(i);
        if (b[i] == '1') bEven.push_back(i);
    }
    
    if (aEven.size() != bEven.size()) {
        cout << "-1\n"; return;
    }
    
    for (ll j=0; j<aEven.size(); j++) {
        res += abs(aEven[j] - bEven[j]) / 2;
    }
    
    vector<ll> a_odd, b_odd;
    for (ll i=1; i<n; i+=2) {
        if (a[i] == '1') a_odd.push_back(i);
        if (b[i] == '1') b_odd.push_back(i);
    }
    
    if (a_odd.size() != b_odd.size()) {
        cout << "-1\n"; return;
    }
    
    for (ll j=0; j<a_odd.size(); j++) {
        res += abs(a_odd[j] - b_odd[j]) / 2;
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