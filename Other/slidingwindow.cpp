#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    queue<int> window;
    window.push(arr[0]);
    while (!window.empty()) {
        int current = window.front();
        int next = arr[current+1];
        if (current + next <= next) { // is using next 
            window.pop();
        }
    }
}