#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, input;
    cin >> n;
    ll switches = 1, curr;
    cin >> input;
    curr = input % 2;
    for (ll i=1; i<n; i++) {
        cin >> input;
        if (input % 2 != curr) {
            curr = input % 2;
            switches++;
        }
    }
    cout << n - switches << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}