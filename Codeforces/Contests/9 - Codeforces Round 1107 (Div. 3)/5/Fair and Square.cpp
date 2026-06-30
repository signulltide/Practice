#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll n;
vector<ll> vals;
vector<bool> visited;
map<ll, vector<ll>> adjList;

void dfs(ll u, vector<ll> &res) {
    res.push_back(u);
    visited[u] = true;
    for (ll v : adjList[u]) {
        if (!visited[v]) {
            dfs(v, res);
        }
    }
}

void Solve() {
    ll u, v;
    cin >> n;
    vals.resize(n+1); visited.resize(n+1);
    for (ll i=1; i<=n; i++) {
        cin >> vals[i];
    }
    for (ll i=0; i<n-1; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    vector<ll> path(0);
    dfs(1, path);
    for (ll i : path) {
        cout << i << " ";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}