#include <iostream>
using namespace std;

#define ll long long

void Solve() {
    ll n, x, y, z;
    cin >> n >> x >> y >> z;
    ll noSpeed = x + y;
    ll noDur = (n + noSpeed - 1) / noSpeed;

    ll yesDur = 0;
    ll setupLines = x * z;

    if (setupLines >= n) {
        yesDur = (n + x - 1) / x;
    } else {
        ll rem = n - setupLines;
        ll yesSpeed = x + 10 * y;
        yesDur = z + (rem + yesSpeed - 1) / yesSpeed;
    }

    cout << min(noDur, yesDur) << '\n';
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