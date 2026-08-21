#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

vector<ll> primes;

void Solve() {
    ll d;
    cin >> d;
    ll p = -1, q = -1;
    for (ll i=0; i<primes.size(); i++) {
        if (p == -1 && primes[i] >= d + 1) {
            p = primes[i];
        } else if (p != -1 && primes[i] >= p + d) {
            q = primes[i];
            break;
        }
    }
    cout << min(p*q, p*p*p) << endl;
}

int main() {
    fastIO;

    for (ll i=2; i<=(ll)1e5; i++) {
        bool prime_Flag = true;
        for (ll j=2; j*j<=i; j++) {
            if (i % j == 0) {
                prime_Flag = false;
                break;
            }
        }
        if (prime_Flag) primes.push_back(i);
    }

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}