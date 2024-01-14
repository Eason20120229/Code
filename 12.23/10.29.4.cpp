/* 归并排序 */
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int a[10000];

// 合并数组的[start, mid]和[mid+1,end]两个区间
void merge(int a[], int l, int r, int mid, int t[]);

// 递归函数，排序数组的[start,end]区间
void f(int a[], int l, int r, int t[]) {
	// 递归出口：单个元素，或者左边界大于右边界
	if (r <= l)
		return;
	// 取中点，将[start,end]区间划分为两个更小的区间
	int mid = (r + l) / 2;
	// 递归处理[start,mid]区间
	f(a, l, mid, t);
	// 递归处理[mid+1,end]区间
	f(a, mid + 1, r, t);
	// 归并两个小区间
	merge(a, l, r, mid, t);
}


void merge(int a[], int l, int r, int mid, int t[]) {
	// 定义 i 指针(下标)、j 指针、k 指针
	int i = l;
	int j = mid + 1;
	int k = l;
	// 不断比较 a[i]和 a[j]的大小，直到 i 或者 j 越界
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			// 将 i 位置的元素复制到数组 temp，i 指针、k 指针往后移动
			t[k++] = a[i++];
		} else {
			// 将 j 位置的元素复制到数组 temp，j 指针、k 指针往后移动
			t[k++] = a[j++];
		}
	}
	// 复制剩余元素
	while (i <= mid) {
		t[k++] = a[i++];
	}
	while (j <= r) {
		t[k++] = a[j++];
	}
	// 此时临时数组 temp 的[start,end]区间已经有序
	// 将 temp 中[start,end]之间的元素复制进原始数组
	for (int i = l; i <= r; i++) {
		a[i] = t[i];
	}
}

void mergesort(int a[], int l, int r) {
	// 新开辟一个临时数组
	int *t = new int(r);
	// 递归数组的[l,r]区间，即可完成数组的排序
	f(a, l, r, t);
}

int main() {
	int t = 0;
	while (cin >> a[t]) {
		t++;
	}
	mergesort(a, 0, t - 1);
	for (int i = 0; i < t; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
