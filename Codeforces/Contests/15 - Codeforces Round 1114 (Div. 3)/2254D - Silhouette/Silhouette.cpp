#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> s(n);
    map<ll, ll> freq, orig;
    vin(s);
    for (ll i=0; i<n; i++) {
        freq[s[i]]++;
        orig[s[i]] = 1;
    }
    ll curr = 0, prev_b = -1, prev_f = -1, prev_o = 0;
    for (auto &[b, f] : freq) {
        if (b > 0) {
            if (prev_b == -1) {
                cout << "-1\n"; return;
            }
            
            ll r = b - curr;
            
            if (r % prev_f != 0) { 
                cout << "-1\n"; return; 
            }
            
            orig[prev_b] = r / prev_f;
            
            if (prev_o >= orig[prev_b]) {
                cout << "-1\n"; return;
            }
            
            prev_o = orig[prev_b];
            curr += r;
        }
        prev_b = b;
        prev_f = f;
    }
    orig[prev_b] = prev_o + 1;
    for (ll i=0; i<n; i++) {
        cout << orig[s[i]] << " ";
    }
    cout << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}