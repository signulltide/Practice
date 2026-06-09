#include <iostream>
using namespace std;

void BubbleSort(int a[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void InsertionSort(int a[], int n) {
    for (int i=1; i<n; i++) {
        int current = a[i], j = i-1;
        while (j >= 0 && a[j] > current) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current;
    }
}

void Merge(int a[], int l, int m, int r) {
    int n1 = m-l+1, n2=r-m;
    int L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i]=a[l+i];
    for (int j=0; j<n2; j++) R[j]=a[m+1+j];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if (L[i]<=R[j]) a[k++]=L[i++];
        else a[k++] = R[j++];
    }
    while (i<n1) a[k++]=L[i++];
    while (j<n2) a[k++]=R[j++];
}

void MergeSort(int a[], int l, int r) {
    if (l<r) {
        int m = (l+r)/2;
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        Merge(a, l, m, r);
    }
}

void SelectionSort(int a[], int n) {

}

int main() {
    int arr[5] = {5, 1, 4, 2, 8};
    int i, temp;
    MergeSort(arr, 0, 4);
    for (i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
}