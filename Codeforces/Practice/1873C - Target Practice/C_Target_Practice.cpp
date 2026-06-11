#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long

void Solve() {
    vector<string> target(10);
    ll total = 0;
    for (ll i=1; i<=10; i++) {
        cin >> target[i-1];
        ll max, presumed;
        if (i <= 5) {
            max = i;
        } else {
            max = 11 - i;
        }
        for (ll j=1; j<=10; j++) {
            if (target[i-1][j-1] == '.') continue;
            if (j <= 5) {
                presumed = j;
            } else {
                presumed = 11 - j;
            }
            total += min(presumed, max);
        }
    }
    cout << total << '\n';
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