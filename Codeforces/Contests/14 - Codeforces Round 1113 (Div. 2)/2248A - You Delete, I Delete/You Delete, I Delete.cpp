#include <iostream>
#include <string>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    string s;
    cin >> s;
    bool a = false, b = false;
    for (ll i=0; i<s.length(); i++) {
        if (!a && s[i] == '0') {
            a = true;
            continue;
        }
        if (!b && s[i] == '1') {
            b = true;
            continue;
        }
        cout << s[i];
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