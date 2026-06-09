#include <iostream>
#include <vector>
using namespace std;

vector<int> magnets;

int main() {
    long long int magnetCount;
    int flips, tries;
    int j, k; long long int i;

    cin >> magnetCount >> flips >> tries;

    for (i = 0; i < magnetCount; i++) {
        magnets.push_back(1);
    }

    int start, range;
    for (k = 0; k < flips; k++) {
        cin >> start >> range;
        for (j = start; j < start + range; j++) {
            if (magnets.at(j) == 1) {
                magnets.at(j) = 0;
            } else {
                magnets.at(j) = 1;
            }
        }
    }

    vector<int> pick;
    int currentPick;

    for (i = 0; i < tries; i++) {
        cin >> currentPick;
        pick.push_back(currentPick);
    }

    int count = 0;

    for (i = 0; i < tries; i++) {
        for (j = pick.at(i); j < magnetCount; j++) {
            if (magnets.at(j) == magnets.at(pick.at(i))) {
                count++;
            } else {
                break;
            }
        }
        for (j = pick.at(i)-1; j >=0; j--) {
            if (magnets.at(j) == magnets.at(pick.at(i))) {
                count++;
            } else {
                break;
            }
        }
        cout << count << endl;
        count = 0;
    }

    return 0;
}