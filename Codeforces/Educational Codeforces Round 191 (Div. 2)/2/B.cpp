#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll j=1; j<=n; j++) {
        cout << j << " ";
    }
    if (n % 2 == 0) {
        for (ll j=n; j>=1; j--) {
            cout << j << " ";
        }
        for (ll j=n; j>=1; j--) {
            cout << j << " ";
        }
    } else {
        for (ll j=n; j>=1; j--) {
            if (j == n/2+1) {
                cout << j+1 << " ";
            } else if (j == n/2+2) {
                cout << j-1 << " ";
            } else {
                cout << j << " ";
            }
        }
        for (ll j=n; j>=1; j--) {
            if (j == n/2+1) {
                cout << j+1 << " ";
            } else if (j == n/2+2) {
                cout << j-1 << " ";
            } else {
                cout << j << " ";
            }
        }
    }
    for (ll j=1; j<=n; j++) {
        cout << j << " ";
    }
    cout << endl;
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