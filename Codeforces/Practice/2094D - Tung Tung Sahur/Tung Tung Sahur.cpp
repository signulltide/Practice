#include <iostream>
#include <string.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    string p, s;
    cin >> p >> s;
    ll pi = 0, si = 0;
    ll n = p.length(), m = s.length();
    while (pi < n && si < m) {
        if (p[pi] != s[si]) {
            cout << "NO\n";
            return;
        }
        
        char curr = p[pi];
        ll streak_p = 0, streak_s = 0;
        
        while (pi < n && p[pi] == curr) {
            streak_p++;
            pi++;
        }
        
        while (si < m && s[si] == curr) {
            streak_s++;
            si++;
        }
        
        if (streak_s < streak_p || streak_s > streak_p * 2) {
            cout << "NO\n";
            return;
        }
    }
    
    if (pi == n && si == m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}