#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;

    if (n % 2 == 1 || n < 4) {
        cout << "-1\n";
        return;
    } else {
        ll least = n/6;
        if (n % 6 != 0) least++;
        cout << least << " " << n/4 << endl;
    }

}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}