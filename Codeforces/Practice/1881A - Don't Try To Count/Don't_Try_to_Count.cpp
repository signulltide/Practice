#include <iostream>
#include <string>
using namespace std;

#define ll long long

void Solve() {
    string x, s;
    ll n, m;
    cin >> n >> m >> x >> s;
    for (ll i=0; i<=5; i++) {
        if (x.find(s) != string::npos) {
            cout << i << '\n';
            return;
        }
        x += x;
    }
    cout << "-1\n";
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