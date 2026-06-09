#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

#define ll long long

ll y, x;
vector<pair<ll, ll>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isInside(ll i, ll j) {
    if (i >= 0 && i < y && j >= 0 && j < x) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a;
    cin >> y >> x;
    vector<vector<ll>> grid(y, vector<ll>(x, 1));
    for (ll i=0; i<y; i++) {
        for (ll j=0; j<x; j++) {
            cin >> a;
            if (grid[i][j] == -1) continue;
            if (a == 0) {
                for (ll m=-1; m<=1; m++) {
                    for (ll n=-1; n<=1; n++) {
                        if (!isInside(i+m, j+n)) continue;
                        grid[i+m][j+n] = -2;
                    }
                }
            } else {
                if (j == 0 && grid[i][j] != -2) {
                    grid[i][j] = -1;
                    continue;
                }
                grid[i][j] = 0;
            }
        }
    }
    
}