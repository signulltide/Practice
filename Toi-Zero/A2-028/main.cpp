#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n, i, count = 0;
    string id1, id2;
    cin >> n >> id1 >> id2;
    for (i=0; i<n; i++) {
        if (id1[i] + id2[i] - 96 != 9) {
            count++;
        }
    }
    if (count == 0) {
        cout << "YES";
    } else {
        cout << "NO " << count;
    }
    return 0;
}