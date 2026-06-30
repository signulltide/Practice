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
    ll totalTwoCount = 0, currTwoCount = 0;
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] == 2) totalTwoCount++;
    }
    if (totalTwoCount == 0) {
        cout << "1\n";
        return;
    }
    if (totalTwoCount % 2 == 1) {
        cout << "-1\n";
        return;
    }
    for (ll i=0; i<n; i++) {
        if (arr[i] == 2) {
            currTwoCount++;
            if (currTwoCount == totalTwoCount / 2) {
                cout << i + 1 << endl;
            }
        }
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}