#include <iostream>
using namespace std;

int main() {
    int loop, length, width, i, j;
    cin >> loop >> length >> width;
    int current = 0;
    for (i=0; i<width; i++) {
        current = i;
        for (j=0; j<length; j++) {
            printf("%c", current + 'A');
            current++;
            if (current >= loop) current = 0;
        }
        cout << endl;
    }
}
