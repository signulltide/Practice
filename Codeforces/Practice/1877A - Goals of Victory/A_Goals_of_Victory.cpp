#include <iostream>
#include <vector>
using namespace std;

#define ll long long

void Solve() {
    ll n, total = 0, temp;
    cin >> n;
    for (ll i=0; i<n-1; i++) {
        cin >> temp;
        total += temp;
    }
    cout << -1 * total << '\n';
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