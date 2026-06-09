#include <iostream>
#include <vector>
using namespace std;

// time O(2^n) space O(n)

int budget, candyCount;
vector<int> candy;
vector<int> boughtFinal;
int most = 0;

void dfs(int depth, int cost, vector<int> bought) {
    if (cost > most && cost <= budget) {
        most = cost;
        boughtFinal = bought;
    }
    if (cost > budget || depth == candyCount-1) return;
    dfs(depth+1, cost, bought);
    bought.push_back(candy[depth+1]);
    dfs(depth+1, cost+candy[depth+1], bought);
}

int main() {
    cin >> budget >> candyCount;
    candy.resize(candyCount);
    for (int i=0; i<candyCount; i++) {
        cin >> candy[i];
    }
    dfs(0, 0, {});
    dfs(0, candy[0], {candy[0]});
    for (int b : boughtFinal) {
        cout << b << " ";
    }
    cout << endl << most << " " << boughtFinal.size();
}