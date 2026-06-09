#include <iostream>
using namespace std;

typedef struct scores {
    int unit;
    int mid;
    int fi;
    int sum;
};

int main() {
    scores s;
    cin >> s.unit >> s.mid >> s.fi;
    s.sum = s.unit + s.mid + s.fi;
    if (s.sum >= 80) {
        cout << "A";
    } else if (s.sum >= 75) {
        cout << "B+";
    } else if (s.sum >= 70) {
        cout << "B";
    } else if (s.sum >= 65) {
        cout << "C+";
    } else if (s.sum >= 60) {
        cout << "C";
    } else if (s.sum >= 55) {
        cout << "D+";
    } else if (s.sum >= 50) {
        cout << "D";
    } else {
        cout << "F";
    }
}