#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> FindMaxCrossingSubarray(const vector<int> & arr, int low, int mid, int high) {
    int leftSum = -1 * INT_MAX, rightSum = -1 * INT_MAX, sum = 0, maxLeft=mid, maxRight = mid+1;
    for (int i=mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    sum = 0;
    for (int i=mid+1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }
    return {maxLeft, maxRight, leftSum + rightSum};
}

vector<int> FindMaxSubarray(const vector<int> & arr, int low, int high) {
    if (low == high) return {low, high, arr[low]};
    int mid = (low+high)/2;
    vector<int> left = FindMaxSubarray(arr, low, mid);
    vector<int> right = FindMaxSubarray(arr, mid+1, high);
    vector<int> cross = FindMaxCrossingSubarray(arr, low, mid, high);
    if (left[2] >= right[2] && left[2] >= cross[2]) {
        return left;
    } else if (right[2] >= left[2] && right[2] >= cross[2]) {
        return right;
    } else {
        return cross;
    }
}

int main() {
    int n, prev, curr;
    vector<int> diffArr;
    cin >> n;
    for (int i=0; i<n; i++) {
        if (i==0) {
            cin >> prev;
        } else {
            cin >> curr;
            diffArr.push_back(curr-prev);
            prev = curr;
        }
    }
    vector<int> res = FindMaxSubarray(diffArr, 0, n-2);
    cout << res[0] << " " << res[1]+1;
}