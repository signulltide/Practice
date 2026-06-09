#include <iostream>
using namespace std;

int main() {
    string a, b, intersect = "";
    getline(cin, a);
    getline(cin, b);
    int i, j, k;
    for (i=0; i<a.length(); i++) {
        for (j=0; j<b.length(); j++) {
            if (a[i] == b[j]) {
                bool existingFlag = false;
                for (k=0; k<intersect.length(); k++) {
                    if (intersect[k] == a[i]) {
                        existingFlag = true;
                        break;
                    }
                }
                if (existingFlag == false) {
                    intersect += a[i];
                    cout << a[i] << " ";
                }
            }
        }
    }
}
