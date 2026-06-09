#include <iostream>
#include <map>
using namespace std;

#define MAX 10

int main() {    
    ios::sync_with_stdio(false); cin.tie();

    int digit1, digit2, i, j, k;
    cin >> digit1 >> digit2;

    char segment1[MAX][3][3], segment2[MAX][3][3];

    for (i=0; i<digit1; i++) {
        for (j=0; j<3; j++) {
            for (k=0; k<3; k++) {
                cin >> segment1[i][j][k];
            }
        }
    }

    for (i=0; i<digit2; i++) {
        for (j=0; j<3; j++) {
            for (k=0; k<3; k++) {
                cin >> segment2[i][j][k];
            }
        }
    }

    int num1 = 0, num2 = 0;

    for (i=digit1-1; i>=0; i++) {
        if (segment1[i][0][1] == '_') {

        }
    }
}