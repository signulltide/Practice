#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vin(a); vin(b);
    vector<ll> streakA(2*n+1), streakB(2*n+1);

    ll currNum = a[0], currStreak = 1;
    for (ll i=1; i<n; i++) {
        if (a[i] == currNum) {
            currStreak++;
        } else {
            streakA[currNum] = max(streakA[currNum], currStreak);
            currNum = a[i]; currStreak = 1;
        }
    }
    streakA[currNum] = max(streakA[currNum], currStreak);

    currNum = b[0], currStreak = 1;
    for (ll i=1; i<n; i++) {
        if (b[i] == currNum) {
            currStreak++;
        } else {
            streakB[currNum] = max(streakB[currNum], currStreak);
            currNum = b[i]; currStreak = 1;
        }
    }
    streakB[currNum] = max(streakB[currNum], currStreak);

    ll most = 0;
    for (ll i=1; i<=2*n; i++) {
        most = max(most, streakA[i] + streakB[i]);
    }
    cout << most << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}