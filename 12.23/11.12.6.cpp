/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2023-11-12 16:27
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int start, int end) {
	// 选取 start 位置的元素作为中点 pivot，以此为依据将数组划分为两部分
	int pivot = a[start];
	int i = start + 1; // i 下标
	int j = end; // j 下标
	while (i <= j) {
		while (i <= j && a[i] <= pivot)
			i++; // i 下标往右移动，直到 a[i]>pivot
		while (i <= j && a[j] > pivot)
			j--; // j 下标往左移动，直到 a[j]<=pivot
		if (i < j) {
			// 交换 a[i]和 a[j]的值
			swap(a[i], a[j]);
			// i 和 j 往中间靠拢
			i++;
			j--;
		}
	}
	// 交换 pivot 和 a[j]
	// 注意不要写 swap(pivot,a[j])
	swap(a[start], a[j]);
	return j; // 返回中间位置
}

int search(int a[], int n, int k) {
	random_shuffle(a + 1, a + n + 1);
	int t = n - k + 1;
	int s = 1, e = n;
	int mid;
	while (s <= e) {
		mid = partition(a, s, e);
		if (mid == t)
			break;
		else if (mid > t)
			e = mid - 1;
		else
			s = mid + 1;
	}
	return a[mid];
}

int main() {
	int a[1001];
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> k;
	cout << search(a, n, k) << endl;
	return 0;
}
