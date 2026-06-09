#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

#define ll long long int

int main() {
    string s, p;
    cin >> s >> p;
    ll pN = 0, sN = 0, base = 0;
    map<char, ll> hashmap;
    for (ll i=0; i<s.length(); i++) {
        if (!hashmap[s[i]]) {
            base++;
            hashmap[s[i]] = base;
        }
    }
    // for (auto &[z, x] : hashmap) {
    //     cout << z << " = " << x << endl;
    // }
    for (ll i=0; i<p.length(); i++) {
        pN += hashmap[p[i]] * pow(base, p.length() - i - 1);
        sN += hashmap[s[i]] * pow(base, p.length() - i - 1);
    }
    for (ll i=1; i<=s.length()-p.length()+1; i++) {
        if (sN == pN) {
            bool matchFlag = true;
            for (ll j=0; j<p.length(); j++) {
                if (s[i-1+j] != p[j]) {
                    matchFlag = false;
                    break;
                }
            }
            if (matchFlag) {
                cout << i-1 << " ";
            }
        }
        sN = ( ((sN - (hashmap[s[i-1]] * pow(base, p.length() - 1))) * base) + hashmap[s[i + p.length() - 1]] );
    }
}