#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    cin >> n >> k;
    ll max = n - 2;
    if (k > max) {
        cout << "-1\n";
        return;
    }

    ll count0 = (n + 1) / 2; 
    ll count1 = n / 2;

    ll alts = n - 1 - k;
    ll blockCount = alts + 1;

    vector<string> blocks(blockCount);
    
    for (ll i=0; i<blockCount; i++) {
        if (i % 2 == 0) {
            blocks[i] = "0";
            count0--;
        } else {
            blocks[i] = "1";
            count1--;
        }
    }

    blocks[0].append(count0, '0');
    if (blockCount > 1) {
        blocks[1].append(count1, '1');
    }

    for (ll i=0; i<blockCount; i++) {
        cout << blocks[i];
    }
    cout << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}