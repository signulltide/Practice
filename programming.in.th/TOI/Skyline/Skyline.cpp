#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    
    int buildingCount, a;
    vector<int> l, h, r;
    cin >> buildingCount;

    int start = 256;
    int end = 0;

    for (int i=0; i<buildingCount; i++) {
        cin >> a; l.push_back(a);
        if (a < start) start = a;
        cin >> a; h.push_back(a);
        cin >> a; r.push_back(a);
        if (a > end) end = a;
    }

    int latest = -1;

    for (int pos = start; pos <= end + 1; pos++) {
        int highest = 0;
        for (int b = 0; b < buildingCount; b++) {
            if (l[b] <= pos && r[b] > pos) highest = max(highest, h[b]);
        }

        if (highest != latest) {
            cout << pos << " " << highest << " ";
            latest = highest;
        }
    }
}