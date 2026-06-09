#include <iostream>
using namespace std;

int main() {
    string s;
    int i, j;
    cin >> s;
    for (i=0; i<s.length(); i++) {
        char least = i;
        for (j=i+1; j<s.length(); j++) {
            if (s[j] < s[least]) {
                least = j;
            }
        }
        char temp = s[i];
        s[i] = s[least];
        s[least] = temp;
    }
    char latest = s[0];
    cout << s[0] << " ";
    for (i=1; i<s.length(); i++) {
        if (s[i] != latest) {
            cout << s[i] << " ";
            latest = s[i];
        }
    }
}
