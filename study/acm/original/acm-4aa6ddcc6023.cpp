#include <iostream>
#include <vector>
using namespace std;

// 合并两个有序子数组
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;   // 左半部分长度
    int n2 = right - mid;      // 右半部分长度

    // 临时数组
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // 合并两个临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // 处理剩余的元素
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// 递归归并排序
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;  // 递归结束条件

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);       // 排序左半部分
    mergeSort(arr, mid + 1, right);  // 排序右半部分
    merge(arr, left, mid, right);    // 合并左右两部分
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 6, 3};

    cout << "排序前：";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "排序后：";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
