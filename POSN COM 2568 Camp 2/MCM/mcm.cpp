#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> C(arr.size(), vector<int>(arr.size(), 0));

    for (int chainLength = 3; chainLength <= n; chainLength++) {
        for (int i=0; i<=n-chainLength; i++) {
            int j = i + chainLength - 1;
            C[i][j] = INT_MAX;
            for (int k=i+1; k<j; k++) {
                C[i][j] = min(
                    C[i][j],
                    C[i][k] + C[k][j] + arr[i] * arr[k] * arr[j]
                );
            }
        }
    }

    cout << C[0][arr.size() - 1];
}