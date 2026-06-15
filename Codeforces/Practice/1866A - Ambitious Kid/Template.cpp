#include <iostream>
#include <math.h>
using namespace std;

#define ll long long

void Solve() {
    ll n, a, least = LLONG_MAX;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> a;
        least = min(least, abs(a));
    }
    cout << least;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    Solve();

    return 0;
}