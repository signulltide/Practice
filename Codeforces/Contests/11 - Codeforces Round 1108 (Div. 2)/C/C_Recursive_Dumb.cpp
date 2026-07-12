#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll n, c = 0;
vector<ll> arr;

void search(ll sum, ll curr) {
    if (curr >= n) return;

    ll newSum = sum;

    if (curr%2 == 0) {
        newSum += arr[curr];
    } else {
        newSum -= arr[curr];
    }

    if (newSum == 0) c++;

    search(newSum, curr+1);

    search(sum, curr+1);
}

void Solve() {
    cin >> n;
    arr.resize(n);
    vin(arr);
    vector<ll> chosen;
    search(0, 0);
    cout << c + 1 << endl;
    c = 0;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}