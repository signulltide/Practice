#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        ll length, sum, avaliable = 0;
        cin >> length >> sum;
        vector<ll> arr(length);

        for (ll i=0; i<length; i++) {
            cin >> arr[i];
            avaliable += arr[i];
        }

        if (avaliable < sum) {
            cout << "-1\n";
            continue;
        }

        ll l = 0, maxLength = 0, curr = 0;
        
        for (ll r=0; r<length; r++) {
            curr += arr[r];

            while (curr > sum && l <= r) {
                curr -= arr[l];
                l++;
            }

            if (curr == sum) {
                maxLength = max(maxLength, r - l + 1);
            }
        }
        
        cout << length - maxLength << '\n';
        
    }
}