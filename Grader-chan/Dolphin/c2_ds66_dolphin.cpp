#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long int n, s, res = 0;
    cin >> n;
    s = n;
    for (long long int i=1; i<=n; i++) {
        s += 2*(n-i);
        if (i%2==1) {
            res += s%10;
            //cout << s%10 << " ";
            if (i+1>n) break;
            if (i+1==n) {
                res += (s-1)%10;
                //cout << (s-1)%10 << " ";
            } else {
                res += (s+1)%10;
                //cout << (s+1)%10 << " ";
            }
        }
    }
    cout << res;
}