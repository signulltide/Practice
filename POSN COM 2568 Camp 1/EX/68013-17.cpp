#include <iostream>
using namespace std;

int main() {
    string loop;
    int length, width, i, j;
    cin >> loop >> length >> width;
    int current = 0;
    for (i=0; i<width; i++) {
        current = i;
        for (j=0; j<length; j++) {
            cout << loop[current];
            current++;
            if (current >= loop.length()) current = 0;
        }
        cout << endl;
    }
}
