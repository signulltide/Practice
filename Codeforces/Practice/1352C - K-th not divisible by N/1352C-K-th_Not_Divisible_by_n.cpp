#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main() {
    ll n, k, t;
    cin >> t;
    vector<ll> res(t);
    for (ll i=0; i<t; i++) {
        cin >> n >> k;
        res[i] = k + (k-1)/(n-1);
    }
    for (ll r : res) {
        cout << r << '\n';
    }
}