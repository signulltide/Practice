#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, init;
    cin >> n >> init;
    vector<pair<ll, ll>> vil(n); // cost, max;

    for (ll i=0; i<n; i++) {
        cin >> vil[i].second;
    }
    for (ll i=0; i<n; i++) {
        cin >> vil[i].first;
    }

    sort(vil.begin(), vil.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    if (init <= vil[0].first) {
        cout << init * n << endl;
        return;
    }

    ll totalCost = 0, told = -1, current = -1;
    
    while (told < n - 1) {
        told++;
        totalCost += init;
        cout << "";
        while (current < told && told < n - 1) {
            if (vil[current+1].first >= init) {
                totalCost += (n - told - 1) * init;
                told += (n - told - 1);
                continue;
            }
            current++;
            ll willBeTold = min(vil[current].second, n - told - 1);
            told += willBeTold;
            totalCost += willBeTold * vil[current].first;
            cout << "";
        }
    }

    cout << totalCost << endl;

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