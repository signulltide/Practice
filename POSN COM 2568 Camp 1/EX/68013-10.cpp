#include <iostream>
#include <random>
#include <vector>
using namespace std;

void cSort(vector<int>& vec, int s, int e, bool ascending) {
    int i, j, temp;
    if (ascending) {
        for (i=s; i<=e; i++) {
            int least = i;
            for (j=i; j<=e; j++) {
                if (vec[j] < vec[least]) {
                    least = j;
                }
            }
            temp = vec[i];
            vec[i] = vec[least];
            vec[least] = temp;
        }
    } else {
        for (i=s; i<=e; i++) {
            int most = i;
            for (j=i; j<=e; j++) {
                if (vec[j] > vec[most]) {
                    most = j;
                }
            }
            temp = vec[i];
            vec[i] = vec[most];
            vec[most] = temp;
        }
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 99);

    int n, i;
    cin >> n;
    vector<int> num;

    for (i=0; i<n; i++) {
        int random = distrib(gen);
        num.push_back({random});
        cout << random << " ";
    }

    cout << endl;

    int half;

    if (n%2==0) {
        half = n/2-1;
    } else {
        half = n/2;
    }

    cSort(num, 0, half, false);
    cSort(num, half+1, n, true);

    for (i=0; i<n; i++) {
        cout << num[i] << " ";
    }
}
