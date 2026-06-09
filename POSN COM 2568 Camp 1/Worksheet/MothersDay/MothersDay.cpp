#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;;
    int i = 141;
    while (i>0) {
        x--;
        if (x==0) x=7;
        i--;
    }
    cout << x;
}
