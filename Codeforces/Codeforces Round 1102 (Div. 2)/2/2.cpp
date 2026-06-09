#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long

void Solve() {
    ll n, a, r;
    cin >> n;

    if (n == 10) {
        cout << "-1\n";
        return;
    }
    
    r = n % 12;

    if (r <= 9) {
        a = r;
    } else if (r == 10) {
        a = 22;
    } else {
        a = 11;
    }

    ll b = n - a;
    cout << a << ' ' << b << '\n';
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