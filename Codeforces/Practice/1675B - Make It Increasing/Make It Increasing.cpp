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
    vin(arr);
    ll last = arr[n-1], res = 0;
    for (ll i=n-2; i>=0; i--) {
        while (arr[i] >= arr[i+1] && arr[i] > 0) {
            arr[i] /= 2;
            res++;
        }
        if (arr[i] == 0 && arr[i+1] == 0) {
            cout << "-1\n";
            return;
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