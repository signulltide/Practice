#include <iostream>
using namespace std;

// time O(n^4) space O(1)

bool CheckNugget(int n) {
    int i, j, k, sum;
    bool flag = false;
    for (i=0; i<=n/20; i++) {
        for (j=0; j<=n/9; j++) {
            for (k=0; k<=n/6; k++) {
                sum = i*20 + j*9 + k*6;
                if (sum == 0) continue;
                if (n % sum == 0) {
                    flag = true;
                    break;
                }
            }
        }
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, i, existFlag = false;
    cin >> n;
    for (i=6; i<=n; i++) {
        if (CheckNugget(i) == true) {
            existFlag = true;
            cout << i << " ";
        }
    }
    if (existFlag == false) {
        cout << "no";
    }

    return 0;
}