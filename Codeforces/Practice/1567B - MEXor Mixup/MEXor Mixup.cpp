#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll XORTill(ll n) {
	ll a = n % 4;
	if (a == 0)
		return n;
	else if (a == 1)
		return 1;
	else if (a == 2)
		return n + 1;
	else
		return 0;
}

void Solve() {
    ll a, b, res;
    cin >> a >> b;
    ll curr_xor = XORTill(a-1);
    ll y = curr_xor ^ b;
    if (y == 0) {
        res = a;
    } else if (y != 0 && y != a) {
        res = a + 1;
    } else if (y == a) {
        res = a + 2;
    }
    cout << res << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}