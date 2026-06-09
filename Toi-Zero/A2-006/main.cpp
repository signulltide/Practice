#include <iostream>
using namespace std;

const int MAX = 30;
int possibleCount = 0;

int navigate(int currentY, int currentX, char grid[MAX][MAX], int endPos) {
    int i, j;
    // cout << "CURRENT: " << currentY << ", " << currentX << endl;
    // for (i=0; i<endPos; i++) {
    //     for (j=0; j<endPos; j++) {
    //         if (i == currentY && j == currentX) {
    //             cout << 'O';
    //         } else {
    //             cout << grid[i][j];
    //         }
    //     }
    //     cout << endl;
    // }
    if (grid[currentY][currentX] == 'X' || currentX >= endPos || currentY >= endPos) {
        return 0;
    }
    if (currentX == endPos-1 && currentY == endPos-1) {
        //cout << "yay\n";
        return 1;
    }
    return navigate(currentY + 1, currentX, grid, endPos) + navigate(currentY, currentX + 1, grid, endPos);
}

int main() {
    char grid[MAX][MAX];
    int i, j, size;
    cin >> size;
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            cin >> grid[i][j];
        }
    }
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            if (grid[i][j] == '.') {
                //cout << "\nSTART\n";
                if (navigate(i, j, grid, size) >= 1) {
                    possibleCount++;
                }
            }
        }
    }
    cout << possibleCount;
}