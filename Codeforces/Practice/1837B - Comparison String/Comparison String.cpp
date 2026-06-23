#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
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
    ll streak = 1, best = 1;
    char curr = s[0];
    for (ll i=1; i<n; i++) {
        if (s[i] == curr) {
            streak++;
        } else {
            best = max(best, streak);
            curr = s[i];
            streak = 1;
        }
    }
    best = max(best, streak);
    cout << best + 1 << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}