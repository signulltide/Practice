#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

ll n, a;
vector<ll> cats;
vector<ll> sorted;
vector<bool> checked;

bool CheckCage(ll sizeIndex) {
    cout << "CHECKING: " << sizeIndex << " WHICH IS " << sorted[sizeIndex] << endl;
    for (ll i=sizeIndex+1; i<=(n >> 1)-2; i++) {
        if (checked[i]) continue;
        ll inRange = false;
        for (ll j=0; j<n; j++) {
            if (inRange == true && cats[j] > sorted[i]) {
                return false;
            }
            if (sorted[i] == cats[j]) {
                if (inRange == false) {
                    inRange = true;
                } else {
                    checked[i] = true;
                    break;
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    scanf("%d", &n);
    bool already = true;
    for (ll i=0; i<n; i++) {
        scanf("%d", &a);
        cats.push_back(a);
        sorted.push_back(a);
        if (already == true && i%2==1 && cats[i-1] != a) already = false;
    }
    if (already == true) {
        cout << 0;
        return 0;
    }
    checked.resize(n, false);

    sort(sorted.begin(), sorted.end());
    for (ll i=0; i<n/2; i++) {
        sorted[i] = sorted[2*i];
    }
    sorted.resize(n>>1);

    ll possible = (n>>1)/2;
    while (possible > 0 && CheckCage(possible) == true) {
        possible--;
    }
    while (possible < n/2 && CheckCage(possible) == false) {
        possible++;
    }
    cout << sorted[possible];
}