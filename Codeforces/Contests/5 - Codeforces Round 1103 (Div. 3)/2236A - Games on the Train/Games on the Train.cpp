#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

void Solve() {
    ll n, least = LLONG_MAX, most = 0, temp;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        least = min(least, temp);
        most = max(most, temp);
    }
    cout << most + 1 - least << '\n';
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