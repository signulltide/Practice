#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void Solve() {
    ll n;
    bool flag = true;
    cin >> n;
    vector<ll> arr(n);
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
        if (flag == true && arr[i] < arr[0]) {
            flag = false;
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