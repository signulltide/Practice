#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<bool> inStack;
stack<int> st;
bool hasCycle = false;

void dfs(int u) {
    if (hasCycle) return;
    visited[u] = true;
    inStack[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            dfs(v);
        } else if (inStack[v]) {
            hasCycle = true;
            return;
        }
    }
    st.push(u);
    inStack[u] = false;
}

int main() {
    int e, v, a, b;
    cin >> v >> e;
    adjList.resize(v+1);
    visited.resize(v+1, false);
    inStack.resize(v+1, false);
    for (int i=0; i<e; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
    }
    for (int i=1; i<=v; i++) {
        if (!visited[i]) {
            dfs(i);
        }
        if (hasCycle) {
            cout << "cycle detected - toposort not possible";
            return 0;
        }
    }
    cout << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}