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
    ll curr = s.length();
    ll res = 0;
    bool flag_0 = false, flag_5 = false;
    while (curr--) {
        if (flag_0 && (s[curr] == '0' || s[curr] == '5')) {
            res = curr;
            break;
        }
        if (flag_5 && (s[curr] == '7' || s[curr] == '2')) {
            res = curr;
            break;
        }
        if (s[curr] == '0') {
            flag_0 = true;
        } else if (s[curr] == '5') {
            flag_5 = true;
        }
    }
    cout << s.length() - curr - 2 << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}