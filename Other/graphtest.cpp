#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph {
    private:
        map<int, vector<int>> adj;
    public:
        void AddEdge(int f, int s) {
            adj[f].push_back(s);
            adj[s].push_back(f);
        }   
        void Display() {
            for (auto from : adj) {
                cout << from.first << " -> ";
                for (int to : from.second) {
                    cout << to << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Graph g;
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.Display();
}