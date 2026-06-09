#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        ll size, redirs = 1, dir = 0;
        cin >> size;
        vector<ll> arr(size);
        for (ll i=0; i<size; i++) {
            cin >> arr[i];
        }
        if (size == 1) {
            cout << "1\n";
            continue;
        }
        for (ll i=1; i<size; i++) {
            if (arr[i] > arr[i-1] && dir != 1) {
                dir = 1;
                redirs++;
            } else if (arr[i] < arr[i-1] && dir != -1) {
                dir = -1;
                redirs++;
            }
        }
        cout << redirs << '\n';
    }
}