#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

void Solve() {
    ll n, k;
    bool flag = false;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] == k) {
            flag = true;
        }
    }
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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