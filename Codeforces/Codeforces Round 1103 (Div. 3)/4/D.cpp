#include <iostream>
#include <vector>
using namespace std;

#define ll long long

void Solve() {
    ll n, k, temp;
    cin >> n >> k;

    vector<ll> count(n+k+5, 0);
    for (ll i = 0; i < n; i++) {
        cin >> temp;
        count[temp]++;
    }

    vector<ll> bad(n+k+5, 0);
    ll windowBad = 0;
    bool flag = false;

    for (ll i=n; i>=1; i--) {
        if (count[i] > 0) {
            if (count[i] % 2 == 1 && windowBad == 0) {
                bad[i] = 1;
            }
            if (!bad[i]) flag = true;
        }

        windowBad += bad[i];

        if (i+k <= n) {
            windowBad -= bad[i+k];
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}