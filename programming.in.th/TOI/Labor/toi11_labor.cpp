#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main() {
    ll workerCount, productCount;
    cin >> workerCount >> productCount;
    vector<ll> workers(workerCount);
    for (ll i=0; i<workerCount; i++) {
        cin >> workers[i];
    }
    
}