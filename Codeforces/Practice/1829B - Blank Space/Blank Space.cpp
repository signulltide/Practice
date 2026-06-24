#include <iostream>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, temp, streak = 0, best = 0;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        if (temp == 0) {
            streak++;
        } else {
            best = max(best, streak);
            streak = 0;
        }
    }
    best = max(best, streak);
    cout << best << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}