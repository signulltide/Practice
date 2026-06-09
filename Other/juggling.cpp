#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (a%b==0) return b;
    return gcd(b, a%b);
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int g = gcd(n, d);
    for (int i=0; i<g; i++) {
        int start = arr[i];
        int current = i, next;
        while (true) {
            next = (current + g) % n;
            if (next == i) break;
            arr[current] = arr[next];
            current += g;
        }
        arr[current] = start;
    }
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}