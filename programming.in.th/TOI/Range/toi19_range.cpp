#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>
#include <set>
using namespace std;

#define ll long long int

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll mountainCount, a, b, l, r;
    cin >> mountainCount;
    auto MountainSorting = [](const tuple<ll, ll, ll, ll> &a, const tuple<ll, ll, ll, ll> &b) {
        if (get<0>(a) == get<0>(b)) {
            return get<3>(a) < get<3>(b);
        }
        return get<0>(a) > get<0>(b);
    };
    vector<ll> leftOf(mountainCount);
    priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>, decltype(MountainSorting)> events(MountainSorting); // pos, id, isLeft, other
    for (ll i=0; i<mountainCount; i++) {
        cin >> a >> b;
        l = min(a, b), r = max(a, b);
        events.emplace(l, i, 1, r);
        events.emplace(r, i, 0, l);
        leftOf[i] = l;
    }
    vector<ll> points(mountainCount, 0);
    vector<vector<ll>> children(mountainCount);
    set<ll> active;
    ll mostPoints = 0;
    while (!events.empty()) {
        auto [pos, id, isLeft, other] = events.top(); events.pop();
        if (isLeft) {
            active.insert(id);
        } else {
            active.erase(id);
            for (ll m : active) {
                if (other < leftOf[m]) continue;
                children[m].push_back(id);
            }
            for (ll c : children[id]) {
                points[id] = max(points[id], points[c]);
            }
            points[id] += 1;
        }
    }
    for (ll p : points) {
        mostPoints = max(mostPoints, p);
    }
    cout << mostPoints << '\n';
    for (ll p : points) {
        cout << p << " ";
    }
}