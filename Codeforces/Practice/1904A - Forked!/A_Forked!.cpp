#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    pair<ll, ll> move, king, queen;
    cin >> move.first >> move.second >> king.first >> king.second >> queen.first >> queen.second;
    vector<pair<ll, ll>> movements = {
        {move.first, move.second},
        {-1 * move.first, move.second},
        {move.first, -1 * move.second},
        {-1 * move.first, -1 * move.second},
        {move.second, move.first},
        {-1 * move.second, move.first},
        {move.second, -1 * move.first},
        {-1 * move.second, -1 * move.first}
    };
    if (move.first == move.second) movements.resize(4);
    ll count = 0;
    for (auto &[f, s] : movements) {
        pair<ll, ll> projectedFromKing = {king.first + f, king.second + s};
        if ((abs(projectedFromKing.first - queen.first) == move.first && abs(projectedFromKing.second - queen.second) == move.second) || (abs(projectedFromKing.first - queen.first) == move.second && abs(projectedFromKing.second - queen.second) == move.first)) {
            count++;
        }
    }
    cout << count << endl;
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