#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

vector<vector<ll>> child;
vector<bool> dam;
vector<ll> ans;

bool dfs(ll u) {
    bool hasDam = dam[u];

    for (ll v : child[u]) {
        bool childHasDam = dfs(v);

        if (childHasDam) {
            if (hasDam) {
                ans.push_back(v);
            } else {
                hasDam = true;
            }
        }
    }

    return hasDam;
}

void Solve() {
    ll n;
    cin >> n;

    child.assign(n+1, {});

    for (ll i=2; i<=n; i++) {
        ll p;
        cin >> p;
        child[p].push_back(i);
    }

    ll m;
    cin >> m;

    dam.assign(n+1, false);

    for (ll i=0; i<m; i++) {
        ll a;
        cin >> a;
        dam[a] = true;
    }

    ans.clear();
    dfs(1);

    cout << ans.size() << " ";
    vout(ans);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}