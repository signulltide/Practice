#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    // vector<ll> arr(3);
    // vin(arr);
    // ll count = 0;
    // while (arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2]) {
    //     ll least = 0, most = 0;
    //     for (ll i=1; i<3; i++) {
    //         if (arr[i] < least) {

    //         }
    //     }
    //     count++;
    // }
    // cout << count;
    ll a, b, c;
    cin >> a >> b >> c;
    ll ab = abs(a-b), bc = abs(b-c), ac = abs(a-c);
    cout << min(min(ab, bc), ac) << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}