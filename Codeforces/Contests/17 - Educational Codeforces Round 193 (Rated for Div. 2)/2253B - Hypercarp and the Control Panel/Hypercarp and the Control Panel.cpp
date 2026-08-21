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
    ll last = arr[0], res = 1;
    for (ll i=1; i<n; i++) {
        if (arr[i] != last) {
            last = arr[i];
            res++;
        }
    }

    // +2 conds
    for (ll i=0; i<n-1; i++) {
        if (arr[i] == arr[i+1]) continue;

        if ((i > 0 && arr[i] == arr[i-1]) && (i+2 < n && arr[i+1] == arr[i+2])) { // both same

            if ((i+2 >= n || arr[i] != arr[i+2]) && (i-1 <= 0 || arr[i+1] != arr[i-1])) {
                cout << res + 2 << endl;
                return;
            }

        }
    }

    // +1 conds
    for (ll i=0; i<n-1; i++) {
        if (arr[i] == arr[i+1]) continue;

        if (i > 0 && arr[i] == arr[i-1]) { // left same

            if ((i+2 >= n || arr[i] != arr[i+2]) && (i-1 < 0 || arr[i+1] != arr[i-1])) {
                cout << res + 1 << endl;
                return;
            }
            
        } else if (i+2 < n && arr[i+1] == arr[i+2]) { // right same

            if ((i+2 >= n || arr[i] != arr[i+2]) && (i-1 < 0 || arr[i+1] != arr[i-1])) {
                cout << res + 1 << endl;
                return;
            }

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