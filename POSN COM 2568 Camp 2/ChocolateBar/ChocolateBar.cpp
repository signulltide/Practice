#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll barLength, flavorCount, desiredCount, x;
    ll uniqueMatches = 0;
    cin >> barLength >> flavorCount >> desiredCount;
    vector<ll> bar(barLength);
    unordered_set<ll> desired;
    unordered_map<ll, ll> freq;
    for (ll i=0; i<barLength; i++) {
        cin >> bar[i];
    }
    for (ll i=0; i<desiredCount; i++) {
        cin >> x;
        desired.insert(x);
    }
    ll left = 0, minLen = barLength + 1;
    for (ll right=0; right<barLength; right++) {
        if (desired.count(bar[right])) {
            freq[bar[right]]++;
            if (freq[bar[right]] == 1) {
                uniqueMatches++;
            }
        }
        while (uniqueMatches == desiredCount) {
            minLen = min(minLen, right - left + 1);
            if (desired.count(bar[left])) {
                freq[bar[left]]--;
                if (freq[bar[left]] == 0) {
                    uniqueMatches--;
                }
            }
            left++;
        }
    }   
    cout << minLen * 10;
}