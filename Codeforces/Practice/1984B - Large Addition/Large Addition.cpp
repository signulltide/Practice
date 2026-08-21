#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

void Solve() {
    string s;
    cin >> s;
    if (s[0] != '1' || s[s.length()-1] > '8') {
        cout << "NO\n";
        return;
    }
    for (ll i=1; i<s.length()-1; i++) {
        if (s[i] == '0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}