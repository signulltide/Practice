#include <iostream>
#include <unordered_map>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    for (ll t=0; t<testCount; t++) {
        ll n;
        cin >> n;

        unordered_map<ll, ll> costSum;
        unordered_map<ll, ll> countReach;

        for (ll i=0; i<n; i++) {
            ll x;
            cin >> x;

            unordered_map<ll, ll> seenCost;

            ll steps = 0;

            while (true) {
                if (!seenCost.count(x)) {
                    seenCost[x] = steps;
                }

                if (x == 1) {
                    if (!seenCost.count(2)) {
                        seenCost[2] = steps + 1;
                    }
                    break;
                }

                if (x % 2 == 0) {
                    x /= 2;
                } else {
                    x++;
                }

                steps++;
            }

            for (auto [value, cost] : seenCost) {
                costSum[value] += cost;
                countReach[value]++;
            }
        }

        ll res = LLONG_MAX;

        for (auto [value, total] : costSum) {
            if (countReach[value] == n) {
                res = min(res, total);
            }
        }

        cout << res << '\n';
    }
}