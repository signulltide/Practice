#include <iostream>
using namespace std;

bool checkCompatibility(char a, char b) {
    char data[4] = {'A', 'C', 'T', 'G'};
    int i, ia, ib;
    for (i=0; i<4; i++) {
        if (a == data[i]) {
            ia = i;
        }
        if (b == data[i]) {
            ib = i;
        }
    }
    if (ib % 2 == ia % 2 && ia != ib) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int length, i, mod;
    char strand1[10000], strand2[10000];
    cin >> length;
    for (i=0; i<length; i++) {
        cin >> strand1[i];
    }
    for (i=0; i<length; i++) {
        cin >> strand2[i];
    }
    cin >> mod;
    int s, pos;
    char c;
    for (i=0; i<mod; i++) {
        cin >> s >> pos >> c;
        if (s == 1) {
            strand1[pos] = c;
        } else if (s == 2) {
            strand2[pos] = c;
        }
    }
    for (i=0; i<length; i++) {
        cout << strand1[i] << " ";
    }
    cout << endl;
    for (i=0; i<length; i++) {
        cout << strand2[i] << " ";
    }
    cout << endl;
    int incompatibleCount = 0;
    for (i=0; i<length; i++) {
        if (checkCompatibility(strand1[i], strand2[i]) == false) {
            incompatibleCount++;
        }
    }
    cout << incompatibleCount;
}