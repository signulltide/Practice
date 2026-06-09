#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i, j, most = 0, current;
    vector<int> data;
    cout << "Input index : ";
    cin >> n;
    for (i=0; i<n; i++) {
        printf("Input Number [%d] : ", i);
        cin >> current;
        if (current > most) {
            most = current;
        }
        data.push_back(current);
    }
    string start = " ";
    for (i=0; i<n; i++) {
        start += " _";
    }
    cout << start << endl;
    for (i=most+1; i>=-2; i--) {
        for (j=-2; j<=n*2-1; j++) {
            if (j%2==0) {
                if (j==-2 && i >= 0) {
                    cout << i;
                } else if (i==-2 && j >= 0) {
                    cout << j/2;
                } else if (i==-1 && j >= 0) {
                    cout << "_";
                } else if (j >= 0 && i <= data[j/2]) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
