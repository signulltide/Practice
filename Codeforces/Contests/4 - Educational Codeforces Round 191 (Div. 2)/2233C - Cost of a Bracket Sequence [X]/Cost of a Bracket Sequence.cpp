#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long

void Solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vector<ll> res(n, 0);
    for (ll i=0; i<n; i++) {
        if (s[i] == '(') {
            for (ll j=n; j>i; j--) {
                if (s[j] == ')') {
                    res[j] = 1;
                }
            }
        }
    }
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