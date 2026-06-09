#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, j, digit = 1, current, sum = 0;
    string s;
    cin >> s;
    vector<int> num;

    for (i=0; i<s.length(); i++) {
        current = ((s[i] - '0')%(digit*10))/digit;
        sum += current;
        num.push_back(current);
    }

    cout << sum;
}
