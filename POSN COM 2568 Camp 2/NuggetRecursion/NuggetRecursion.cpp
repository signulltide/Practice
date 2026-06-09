#include <iostream>
#include <vector>
using namespace std;

//time O(n) space O(n)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if (n < 6) {
        cout << "no";
        return 0;
    } 
    vector<bool> nuggets(n+1, false);
    nuggets[0] = true;
    for (int i=6; i<=n; i++) {
        if (nuggets[i-6] || (i >= 9 && nuggets[i-9]) || (i >= 20 && nuggets[i-20])) {
            nuggets[i] = true;
            cout << i << endl;
        }
    }
}