#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vin(arr);
    if (n%2==0) {
        cout << "2\n";
        cout << 1 << " " << n << endl << 1 << " " << n << endl;
    } else {
        cout << "4\n";
        cout << 1 << " " << n-1 << endl << 1 << " " << n-1 << endl;
        cout << n-1 << " " << n << endl << n-1 << " " << n << endl;
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}