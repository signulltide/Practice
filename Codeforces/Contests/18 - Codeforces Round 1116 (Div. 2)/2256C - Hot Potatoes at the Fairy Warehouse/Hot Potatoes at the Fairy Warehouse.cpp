#include <iostream>
#include <string>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll oddDeaths = 0, evenDeaths = 0;
    for (ll i=0; i<n*2; i++) {
        ll next = (i+1)%(n*2);
        if (s[i] == '1') {
            if (s[next] == '0') {
                if (i%2 == 0) {
                    evenDeaths++;
                } else {
                    oddDeaths++;
                }
            } else {
                if (i%2 == 0) {
                    oddDeaths++;
                } else {
                    evenDeaths++;
                }
            }
        }
    }
    cout << evenDeaths << " " << oddDeaths << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}