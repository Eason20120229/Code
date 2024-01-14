/*********************************************************************
    ������:
    ��Ȩ:
    ����:
    ����: 2023-11-12 16:27
    ˵��:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int start, int end) {
	// ѡȡ start λ�õ�Ԫ����Ϊ�е� pivot���Դ�Ϊ���ݽ����黮��Ϊ������
	int pivot = a[start];
	int i = start + 1; // i �±�
	int j = end; // j �±�
	while (i <= j) {
		while (i <= j && a[i] <= pivot)
			i++; // i �±������ƶ���ֱ�� a[i]>pivot
		while (i <= j && a[j] > pivot)
			j--; // j �±������ƶ���ֱ�� a[j]<=pivot
		if (i < j) {
			// ���� a[i]�� a[j]��ֵ
			swap(a[i], a[j]);
			// i �� j ���м俿£
			i++;
			j--;
		}
	}
	// ���� pivot �� a[j]
	// ע�ⲻҪд swap(pivot,a[j])
	swap(a[start], a[j]);
	return j; // �����м�λ��
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
