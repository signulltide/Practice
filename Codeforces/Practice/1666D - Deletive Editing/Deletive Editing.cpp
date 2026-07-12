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
    string s, t;
    vector<bool> present(26, false);
    vector<ll> found(26, 0);
    cin >> s >> t;
    for (char lt : t) {
        present[lt - 'A'] = true;
        found[lt - 'A']++;
    }
    ll curr = t.length() - 1;
    for (ll i=s.length()-1; i>=0; i--) {
        if (present[s[i] - 'A']) {
            //cout << s[i] << " IS PRESENT\n";
            if (found[s[i] - 'A'] == 0) continue;
            if (s[i] == t[curr]) {
                curr--;
                found[s[i] - 'A']--;
                //cout << s[i] << " IS CURR\n";
            } else {
                //cout << s[i] << " IS NOT CURR\n";
                cout << "NO\n";
                return;
            }
        }
    }
    for (char lt : t) {
        if (found[lt - 'A'] > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}