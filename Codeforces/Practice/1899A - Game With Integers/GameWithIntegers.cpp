#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int testCount, curr;
    vector<bool> res;
    cin >> testCount;

    for (int i=0; i<testCount; i++) {
        cin >> curr;
        if (curr%3 == 0) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
    }

    for (bool r : res) {
        if (r) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    }
}