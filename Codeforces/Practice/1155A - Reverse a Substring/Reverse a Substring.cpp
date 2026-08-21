#include <iostream>
#include <string>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    string s;
    cin >> n >> s;

    for (ll i=1; i<n; i++) {
        if (s[i] < s[i-1]) {
            cout << "YES\n" << i << " " << i+1 << endl;
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    fastIO;

    Solve();
    
    return 0;
}