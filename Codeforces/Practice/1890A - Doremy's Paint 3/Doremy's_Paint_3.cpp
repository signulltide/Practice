#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

#define ll long long

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> freq;
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    ll f1 = freq.begin()->second;
    ll f2 = freq.rbegin()->second;
    if (freq.size() > 2) {
        cout << "No\n";
    } else if (f1 == f2 || abs(f1 - f2) == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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