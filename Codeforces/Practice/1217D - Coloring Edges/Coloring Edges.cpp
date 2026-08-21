#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

vector<vector<ll>> adjList;
vector<ll> visited;
map<pair<ll, ll>, ll> color;
map<ll, pair<ll, ll>> order;
ll most = 1;

void dfs(ll u) {

    visited[u] = 1;

    for (ll v : adjList[u]) {
        if (visited[v] == 2) continue;
        if (visited[v] == 1) {
            //cout << "CYCLE\n";
            color[{u, v}] = 2;
            most = 2;
            continue;
        }
        //vout(visited);
        //cout << u + 1 << " -> " << v + 1 << endl;
        dfs(v);
    }

    visited[u] = 2;
}

int main() {
    fastIO;

    ll v, e, p, q;
    cin >> v >> e;
    adjList.resize(v);
    visited.assign(v, 0);
    for (ll i=0; i<e; i++) {
        cin >> p >> q;
        p--; q--;
        adjList[p].push_back(q);
        color[{p, q}] = 1;
        order[i] = {p, q};
    }

    vector<bool> visited(v, false);
    vector<bool> recStack(v, false);

    for (ll i=0; i<v; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    cout << most << endl;
    for (ll i=0; i<e; i++) {
        cout << color[order[i]] << " ";
    }

    return 0;
}