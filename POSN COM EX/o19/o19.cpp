#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int x) {
    int i, found = -1;
    for (i=0; i<n; i++) {
        if (arr[i] == x) {
            found = i;
            break;
        }
    }
    return found;
}

int BinarySearch(int a[], int left, int right, int x) {
    int mid = (right + left) / 2;
    if (x > right || x < left) return -1;
    if (x > a[mid]) {
        return BinarySearch(a, mid+1, right, x);
    } else if (x < a[mid]) {
        return BinarySearch(a, left, mid-1, x);
    } else if (x == a[mid]) {
        return mid;
    }
}

int main() {
    int arr[10] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 101};
    int index = BinarySearch(arr, 0, 9, 13);
    cout << index;
}