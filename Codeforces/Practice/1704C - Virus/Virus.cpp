#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void Solve() {
    ll n, m, safe = 0;
    cin >> n >> m;
    vector<ll> init(m), range(m);
    for (ll i=0; i<m; i++) {
        cin >> init[i];
    }
    sort(init.begin(), init.end());
    for (ll i=1; i<m; i++) {
        range[i-1] = init[i] - init[i-1] - 1;
    }
    range[m-1] = n - init[m-1] + init[0] - 1;
    sort(range.begin(), range.end(), greater<ll>());
    ll days = 0;
    for (ll i=0; i<m; i++) {
        if (range[i] - (days * 2) > 0) {
            safe += max(1ll, range[i] - (days * 2) - 1);
            days += 2;
        }
    }
    cout << n - safe << '\n';
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