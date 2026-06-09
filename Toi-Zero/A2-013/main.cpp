#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n, rabbits[10000], topIndex = 0, count = 0, i;
    string names[10000];
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> names[i] >> rabbits[i];
        if (rabbits[i] > rabbits[topIndex]) {
            topIndex = i;
        }
        if (rabbits[i] > 15) {
            count++;
        }
    }
    cout << count << endl << names[topIndex] << " " << rabbits[topIndex];
}