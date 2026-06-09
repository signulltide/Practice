#include <iostream>
#include <map>
using namespace std;

int main() {
    int vowels[5] = {0, 0, 0, 0, 0};
    string s;
    getline(cin, s);
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'A') {
            vowels[0]++;
        } else if (s[i] == 'e' || s[i] == 'E') {
            vowels[1]++;
        } else if (s[i] == 'i' || s[i] == 'I') {
            vowels[2]++;
        } else if (s[i] == 'o' || s[i] == 'O') {
            vowels[3]++;
        } else if (s[i] == 'u' || s[i] == 'U') {
            vowels[4]++;
        }
    }
    for (int v : vowels) {
        cout << v << " ";
    }
}
