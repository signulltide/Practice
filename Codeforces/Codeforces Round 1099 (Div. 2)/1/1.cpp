#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    vector<ll> inputs;
    cin >> testCount;

    for (ll t=0; t<testCount; t++) {
        ll count;
        cin >> count;
        inputs.push_back(count);
    }

    for (ll count : inputs) {
        for (ll i=1; i<2*count; i+=2) {
            cout << i << " ";
        }
        cout << endl;
    }
}