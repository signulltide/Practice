#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    int count;
    cin >> count;
    vector<ll> arr(count);
    
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }

    // Step 1: Find the maximum adjacent drop. This is our minimum required 'k'.
    ll k = 0;
    for (int i = 0; i < count - 1; i++) {
        k = max(k, arr[i] - arr[i+1]);
    }

    // Step 2: Greedily build the valid non-decreasing array
    ll prev = arr[0];
    bool possible = true;
    
    for (int i = 1; i < count; i++) {
        // Option 1: Try leaving the element as it is (preferable to keep numbers small)
        if (arr[i] >= prev) {
            prev = arr[i];
        } 
        // Option 2: Try adding k to the element
        else if (arr[i] + k >= prev) {
            prev = arr[i] + k;
        } 
        // If neither is >= the previous element, it's impossible to sort
        else {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int testCount;
    cin >> testCount;
    while (testCount--) {
        solve();
    }
    
    return 0;
}