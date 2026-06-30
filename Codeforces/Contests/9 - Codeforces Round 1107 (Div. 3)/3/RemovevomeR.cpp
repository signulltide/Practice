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
    ll changes = 1;
    char curr = s[0];
    for (ll i=1; i<n; i++) {
        if (curr != s[i]) {
            changes++;
            curr = s[i];
        }
    }
    if (changes == 2) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}