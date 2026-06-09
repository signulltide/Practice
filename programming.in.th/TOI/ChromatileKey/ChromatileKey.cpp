#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int lockLength, keyLength;
    string key, lock1, lock2;
    cin >> lockLength >> keyLength >> lock1 >> lock2 >> key;
    for (int i=0; i<keyLength; i++) {
        for (int j=0; j<lockLength; j++) {
            if (key[i] > lock1[j] && key[i] > lock2[j]) {
                key[i] = max(lock1[j], lock2[j]);
            } else if (key[i] < lock1[j] && key[i] < lock2[j]) {
                key[i] = min(lock1[j], lock2[j]);
            }
        }
    }
    cout << key;
}