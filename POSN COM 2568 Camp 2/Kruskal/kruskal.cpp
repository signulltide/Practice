#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct mapValue {
    int value = -1;
};

class UFDS {
    private:
        map<int, mapValue> parent;

    public:

        int Find(int i) { // find representative index (ultimate parent)
            if (parent[i].value < 0) return i;
            return Find(parent[i].value);
        }

        void Unite(int i, int j) { // check if same rep first before calling
            int irep = Find(i);
            int jrep = Find(j);
            if (parent[irep].value < parent[jrep].value) {
                parent[jrep].value = irep;
            } else {
                parent[irep].value = jrep;
            }
        }
};

struct CompareTuples {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[2] > b[2]; 
    }
};

int main() {
    int vertexCount, edgeCount, u, v, w, totalCost = 0, finalEdgeCount = 0;
    cin >> vertexCount >> edgeCount;
    priority_queue<vector<int>, vector<vector<int>>, CompareTuples> edgeList;
    map<int, vector<int>> mcst;
    UFDS ufds;
    for (int i=0; i<edgeCount; i++) {
        cin >> u >> v >> w;
        edgeList.push({u, v, w});
    }
    cout << "Edges in MCST:\n";
    while (!edgeList.empty()) {
        vector<int> curr = edgeList.top(); edgeList.pop();
        int cu = curr[0], cv = curr[1], cw = curr[2];
        if (ufds.Find(cu) != ufds.Find(cv)) {
            ufds.Unite(cu, cv);
            cout << cu << " —— " << cv << "\t| COST: " << cw << endl;
            totalCost += cw;
            finalEdgeCount++;
            if (finalEdgeCount == vertexCount - 1) break;
        }
    }
    cout << "Final cost: " << totalCost;
}