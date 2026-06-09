#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string keyString, codeString;
    cin >> keyString >> codeString;
    vector<int> key, code;
    for (char k : keyString) {
        key.push_back(k - '0');
    }
    for (char c : codeString) {
        code.push_back(c - '0');
    }
    
    vector<int> res;
    int oKey0 = key[0], oKey2 = key[2];
    
    int times = 0;
    for (int c : code) {
        times++;
        int first = (key[0]+(c-1))%9; if (first == 0) first = 9;
        int second = (key[1]+(first-1))%9; if (second == 0) second = 9;
        int third = (key[2]+(second-1))%9; if (third == 0) third = 9;
        res.push_back(third);
        if (times <= 1) {
            key[0] = (2*key[0])%9; if (key[0] == 0) key[0] = 9;
            key[2] = (2*key[2])%9; if (key[2] == 0) key[2] = 9;
        } else {
            key[0] = (key[0] + oKey0)%9; if (key[0] == 0) key[0] = 9;
            key[2] = (key[2] + oKey2)%9; if (key[2] == 0) key[2] = 9;
        }
        key[1] = (key[1]-1)%9; if (key[1] == 0) key[1] = 9;
    }

    for (int r : res) {
        cout << r;
    }
}