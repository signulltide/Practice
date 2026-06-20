#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

#define ll long long

void Solve() {
    ll n, temp;
    cin >> n;
    vector<ll> arr(n);
    vector<bool> taken(n, false);
    vector<pair<ll, ll>> sorted; // val, orig
    map<ll, ll> freq;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        arr[i] = temp;
        sorted.push_back({temp, i});
        freq[temp]++;
    }
    sort(sorted.begin(), sorted.end());
    ll best = 0, curr = 0, cl, cr;
    for (ll i=0; i<n; i++) {
        if (taken[i]) continue;
        if (curr == 0) {
            curr++;
            cl = sorted[i].second;
            cr = sorted[i].second;
        } else {
            if (sorted[i].first - sorted[i-1].first == 1) {
                for (ll j=0; j<freq[sorted[i].first]; j++) {
                    if (cl - sorted[i+j].second == 1) {
                        curr++;
                        cl = sorted[i+j].second;
                        taken[i+j] = true;
                        break;
                    } else if (sorted[i+j].second - cr == 1) {
                        curr++;
                        cr = sorted[i+j].second;
                        taken[i+j] = true;
                        break;
                    }
                }
            } else {
                best = max(best, curr);
                curr = 0;
                i--;
                taken.assign(n, false);
            }
        }
    }
    best = max(best, curr);
    cout << best/2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}

// what was i doing