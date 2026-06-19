#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> prefixSum(n);
    prefixSum[0] = s[0] - '0' + 1;
    for (ll i=1; i<n; i++) {
        prefixSum[i] = prefixSum[i-1] + s[i] - '0' + 1;
    }
    ll currLength = 0;
    ll beautyCount = 0, altCount = 0;
    for (ll i=0; i<n; i++) {
        if (i > 0 && s[i] == s[i-1]) {
            altCount += (currLength * (currLength + 1)) / 2;
            currLength = 1;
        } else {
            currLength++;
        }
        for (ll j=i; j<n; j++) {
            ll curr;
            if (i > 0) {
                curr = prefixSum[j] - prefixSum[i-1];
            } else {
                curr = prefixSum[j];
            }
            if (curr % 3 != 0) {
                beautyCount++;
            }
        }
    }
    cout << beautyCount - altCount << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}