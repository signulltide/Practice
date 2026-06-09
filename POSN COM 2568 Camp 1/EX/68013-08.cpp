#include <iostream>
using namespace std;

int main() {
    string dirty, clean = " ";
    cin >> dirty;
    int i, c = 1;
    char latest = dirty[0];
    clean[0] = dirty[0];
    for (i=1; i<dirty.length(); i++) {
        if (dirty[i] != latest) {
            clean += dirty[i];
            latest = dirty[i];
            c++;
        }
    }
    cout << clean;
}
