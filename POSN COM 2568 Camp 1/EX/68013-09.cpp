#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, j, digit = 1, error = false, current;
    string s;
    cin >> s;
    vector<int> num;

    for (i=0; i<s.length(); i++) {
        current = ((s[i] - '0')%(digit*10))/digit;
        if (current > 6) {
            error = true;
            break;
        }
        num.push_back(current);
    }

    if (error) {
        cout << "error";
        return 0;
    }

    vector<vector<char>> grid(3, vector<char>(num.size()*3 + num.size() - 1, ' '));

    int offset = 0;

    for (int n : num) {
        if (n == 1) {
            grid[1][1+offset] = '*';
        } else if (n == 2) {
            grid[1][0+offset] = '*';
            grid[1][2+offset] = '*';
        } else if (n == 3) {
            grid[0][1+offset] = '*';
            grid[1][1+offset] = '*';
            grid[2][1+offset] = '*';
        } else if (n == 4) {
            grid[0][0+offset] = '*';
            grid[2][0+offset] = '*';
            grid[0][2+offset] = '*';
            grid[2][2+offset] = '*';
        } else if (n == 5) {
            grid[0][0+offset] = '*';
            grid[2][0+offset] = '*';
            grid[0][2+offset] = '*';
            grid[2][2+offset] = '*';
            grid[1][1+offset] = '*';
        } else if (n == 6) {
            grid[0][0+offset] = '*';
            grid[1][0+offset] = '*';
            grid[2][0+offset] = '*';
            grid[0][2+offset] = '*';
            grid[1][2+offset] = '*';
            grid[2][2+offset] = '*';
        }
        offset += 4;
    }

    for (i=0; i<3; i++) {
        for (j=0; j<grid[0].size(); j++) {
            if ((j+1)%4==0) {
                cout << "|";
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
}
