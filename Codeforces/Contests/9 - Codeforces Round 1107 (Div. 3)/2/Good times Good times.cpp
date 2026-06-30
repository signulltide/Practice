#include <iostream>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll x, y;
    cin >> x;
    ll temp_x = x, x_digits = 0;
    while (temp_x > 0) {
        temp_x /= 10;
        x_digits++;
    }
    y = pow(10, x_digits) + 1;
    cout << y << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}