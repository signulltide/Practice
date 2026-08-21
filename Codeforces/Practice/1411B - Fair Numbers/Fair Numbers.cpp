#include <iostream>
#include <string>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;

    while (true) {

        bool flag = true;

        ll digit = 1;
        while (digit <= n) {
            ll curr = (n % (digit * 10)) / digit;
            digit *= 10;
            if (curr == 0) continue;
            if (n % curr != 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << n << endl;
            return;
        }

        n++;
        
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}