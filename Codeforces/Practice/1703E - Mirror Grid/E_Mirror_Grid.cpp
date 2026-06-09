#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {

        ll n, operations = 0;
        string input;
        cin >> n;
        vector<vector<ll>> grid(n, vector<ll>(n));

        for (ll i=0; i<n; i++) {
            cin >> input;
            for (ll j=0; j<n; j++) {
                grid[i][j] = input[j] - '0';
            }   
        }

        for (ll i=0; i<n/2; i++) {
            for (ll j=0; j<n/2; j++) {
                ll a = grid[i][j];
                ll b = grid[j][n-1-i];
                ll c = grid[n-1-i][n-1-j];
                ll d = grid[n-1-j][i];
                ll sum = a + b + c + d;
                if (sum <= 2) {
                    operations += sum;
                } else {
                    operations += 4 - sum;
                }
            }
        }

        if (n%2!=0) {
            for (ll i=0; i<n/2; i++) {
                ll a = grid[i][n/2];
                ll b = grid[n/2][n-1-i];
                ll c = grid[n-1-i][n/2];
                ll d = grid[n/2][i];
                ll sum = a + b + c + d;
                if (sum <= 2) {
                    operations += sum;
                } else {
                    operations += 4 - sum;
                }
            }
        }

        cout << operations << '\n';

    }
}