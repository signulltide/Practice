#include <iostream>
#include <vector>
using namespace std;

bool MatchChar(char a, char b) {
    if (a == b || a == b - 32 || a == b + 32) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<vector<char>> grid;
    int i, j, k, m, n, x, y;
    char c; string s;
    cin >> y >> x;
    for (i=0; i<y; i++) {
        grid.push_back({});
        for (j=0; j<x; j++) {
            cin >> c;
            grid[i].push_back(c);
        }
    }
    int wordCount;
    vector<string> words;
    cin >> wordCount;
    for (i=0; i<wordCount; i++) {
        cin >> s;
        words.push_back(s);
    }
    int originX, originY;
    for (k=0; k<wordCount; k++) {
        //cout << "Searching for " << words[k] << endl;
        bool foundFlag = false;
        for (i=0; i<y; i++) {
            for (j=0; j<x; j++) {
                if (MatchChar(grid[i][j], words[k][0])) {
                    //printf("Found starting point at %d, %d\n", i, j);
                    for (m=-1; m<=1; m++) {
                        for (n=-1; n<=1; n++) {
                            int incrementY = m, incrementX = n, progress = 1;
                            //printf("Incrementing by %d, %d\n", m, n);
                            if (i + incrementY * (words[k].length() - 1) >= y || i + incrementY * (words[k].length() - 1) < 0 || j + incrementX * (words[k].length() - 1) >= x || j + incrementX * (words[k].length() - 1) < 0) continue;
                            while (MatchChar(grid[i+incrementY][j+incrementX], words[k][progress])) {
                                //printf("Matching %c at %d, %d (Actual: %c)\n", words[k][progress], i+incrementY, j+incrementX, grid[i+incrementY][j+incrementX]);
                                incrementY += m, incrementX += n;
                                progress++;
                                if (progress == words[k].length()) {
                                    break;
                                }
                            }
                            if (progress == words[k].length()) {
                                foundFlag = true;
                                cout << i << " " << j << endl;
                            }
                            if (foundFlag == true) break;
                        }
                        if (foundFlag == true) break;
                    }
                }
                if (foundFlag == true) break;
            }
            if (foundFlag == true) break;
        }
        foundFlag = false;
    }
}