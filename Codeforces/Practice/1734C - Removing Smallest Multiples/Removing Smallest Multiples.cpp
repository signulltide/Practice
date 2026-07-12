#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, res = 0;
    string s;
    cin >> n >> s;
    vector<bool> visited(n+1, false);
    for (ll i=1; i<=n; i++) {
        for (ll j=i; j<=n; j+=i) {
            if (visited[j]) continue;
            if (s[j-1] == '1') break;
            if (s[j-1] == '0') {
                res += i;
            }
            visited[j] = true;
        }
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