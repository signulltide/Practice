#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    char c;
    string s;
    cin >> n >> c >> s;
    s += s;
    if (c == 'g') {
        cout << "0\n";
        return;
    }
    ll worst = 0, found = -1;
    for (ll i=0; i<n*2; i++) {
        if (s[i] == c && found == -1) {
            found = i;
        } else if (s[i] == 'g' && found > -1) {
            worst = max(worst, i - found);
            found = -1;
        }
    }
    cout << worst << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}