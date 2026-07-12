#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    
    cout << 1 << " " << 2 << " ";
    
    ll curr = 3;
    for (ll i=0; i<n-2; i++) {
        cout << curr << (i == n - 3 ? "" : " ");
        curr *= 2;
    }
    cout << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}