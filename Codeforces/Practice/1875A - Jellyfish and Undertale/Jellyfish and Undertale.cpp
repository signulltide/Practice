#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll cap, init, toolCount;
    cin >> cap >> init >> toolCount;
    vector<ll> tools(toolCount);
    vin(tools);
    ll res = init;
    for (ll i=0; i<toolCount; i++) {
        res += min(cap-1, tools[i]);
    }
    cout << res << endl;
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

// why would flowey do that??