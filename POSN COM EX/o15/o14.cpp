#include <iostream>
using namespace std;

int main() {
    int size, type, i, j, comp;
    char in, out, border, c;

    cin >> size >> type >> c;

    if (size%2==0) {
        cout << "Please input an odd size.";
        return 0;
    }

    switch(type) {
        case 1:
            in = ' '; border = c; out = ' ';
            break;
        case 2:
            in = c; border = c; out = ' ';
            break;
        case 3:
            in = ' '; border = c; out = c;
            break;
        default:
            cout << "Input a type ranging from 1 to 3.";
            return 0;
    }

    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            if (i <= size/2) {
                if (j < size/2 - i || j > size/2 + i) {
                    cout << out;
                } else if (j == size/2 - i || j == size/2 + i) {
                    cout << border;
                } else if (j > size/2 - i && j < size/2 + i) {
                    cout << in;
                }
            } else {
                if (j < i - size/2 || j > size/2 + (i)) {
                    cout << out;
                } else if (j == i - size/2 || j == i) {
                    cout << border;
                } else if (j > i - size/2 && j < i) {
                    cout << in;
                }
            }
        }
        cout << endl;
    }



}