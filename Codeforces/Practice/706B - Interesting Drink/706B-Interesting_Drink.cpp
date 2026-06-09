#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> shops;

int main() {
    int shopCount, dayCount;
    cin >> shopCount;
    shops.resize(shopCount);
    for (int i=0; i<shopCount; i++) {
        cin >> shops[i];
    }
    sort(shops.begin(), shops.end());
    cin >> dayCount;
    vector<int> coins(dayCount);
    for (int i=0; i<dayCount; i++) {
        cin >> coins[i];
    }
    for (int i=0; i<dayCount; i++) {
        int l = 0, r = shopCount-1, mid, res;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (coins[i] >= shops[mid]) {
                l = mid+1;
            } else {
                r = mid;
            }

        }
        if (shops[l] <= coins[i]) {
            res = l + 1;
        } else {
            res = l;
        }
        cout << res << "\n";
    }
}