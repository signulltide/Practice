#include <iostream>
#include <deque>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

string NameComparision(string a, string b) {
    string shorter;
    if (a <= b) {shorter = a;} else {shorter = b;}
    for (int i=0; i<shorter.length(); i++) {
        if (a[i] < b[i]) {
            return a;
        } else if (b[i] < a[i]) {
            return b;
        }
    }
    return shorter;
}

deque<int> StringToIntDeque(string s) {
    int digit = 1, current = 0;
    deque<int> res;
    for (int i=s.length()-1; i>=0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            current += (s[i]-'0')*digit;
            digit *= 10;
        } else if (s[i] == ' ') {
            res.push_front(current);
            digit = 1; current = 0;
        } else {
            break;
        }
    }
    return res;
}

deque<pair<string, int>> current;

void AddToCurrent(string n, int o) {
    if (current.size() < 3) {
        current.push_back({n, o});
        sort(current.begin(), current.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second || (a.second == b.second && NameComparision(a.first, b.first) == a.first);
        });
        return;
    }
    string bn = current.back().first;
    int bo = current.back().second;
    if (o < bo || (o == bo && NameComparision(n, bn) == n)) {
        current.pop_back();
        current.push_back({n, o});
        sort(current.begin(), current.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second || (a.second == b.second && NameComparision(a.first, b.first) == a.first);
        });
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    deque<pair<string, deque<int>>> traveller;
    int n, k;
    string s;
    cin >> n >> k;
    cin.ignore();
    for (int i=0; i<n; i++) {
        getline(cin, s);
        deque<int> rests = StringToIntDeque(s);
        string name;
        for (char c : s) {
            if (c == ' ') break;
            name.push_back(c);
        }
        traveller.push_back({name, rests});
    }
    for (auto t : traveller) {
        string name = t.first;
        deque<int> rests = t.second;
        for (int i=0; i<rests.size(); i++) {
            if (rests[i] == k) {
                AddToCurrent(name, i);
                break;
            }
        }
    }
    if (current.size() == 0) {
        cout << -1;
        return 0;
    }
    for (auto c : current) {
        cout << c.first << " ";
    }
    return 0;
}