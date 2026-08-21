#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    
    ll total_sticks_needed = k * y + k;
    ll sticks_to_gain = total_sticks_needed - 1;
    ll d = x - 1;
    
    ll stick_trades = (sticks_to_gain + d - 1) / d;
    ll coal_trades = k;
    
    cout << stick_trades + coal_trades << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}