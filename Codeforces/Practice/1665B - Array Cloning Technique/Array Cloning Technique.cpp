#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    double n, temp;
    cin >> n;
    map<ll, double> freq;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        freq[temp]++;
    }
    double most = 0;
    for (auto &[n, f] : freq) {
        most = max(most, f);
    }
    double res = (n - most) + log2(n/most);
    cout << ceil(res) << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}