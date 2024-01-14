/* �鲢���� */
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int a[10000];

// �ϲ������[start, mid]��[mid+1,end]��������
void merge(int a[], int l, int r, int mid, int t[]);

// �ݹ麯�������������[start,end]����
void f(int a[], int l, int r, int t[]) {
	// �ݹ���ڣ�����Ԫ�أ�������߽�����ұ߽�
	if (r <= l)
		return;
	// ȡ�е㣬��[start,end]���仮��Ϊ������С������
	int mid = (r + l) / 2;
	// �ݹ鴦��[start,mid]����
	f(a, l, mid, t);
	// �ݹ鴦��[mid+1,end]����
	f(a, mid + 1, r, t);
	// �鲢����С����
	merge(a, l, r, mid, t);
}


void merge(int a[], int l, int r, int mid, int t[]) {
	// ���� i ָ��(�±�)��j ָ�롢k ָ��
	int i = l;
	int j = mid + 1;
	int k = l;
	// ���ϱȽ� a[i]�� a[j]�Ĵ�С��ֱ�� i ���� j Խ��
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			// �� i λ�õ�Ԫ�ظ��Ƶ����� temp��i ָ�롢k ָ�������ƶ�
			t[k++] = a[i++];
		} else {
			// �� j λ�õ�Ԫ�ظ��Ƶ����� temp��j ָ�롢k ָ�������ƶ�
			t[k++] = a[j++];
		}
	}
	// ����ʣ��Ԫ��
	while (i <= mid) {
		t[k++] = a[i++];
	}
	while (j <= r) {
		t[k++] = a[j++];
	}
	// ��ʱ��ʱ���� temp ��[start,end]�����Ѿ�����
	// �� temp ��[start,end]֮���Ԫ�ظ��ƽ�ԭʼ����
	for (int i = l; i <= r; i++) {
		a[i] = t[i];
	}
}

void mergesort(int a[], int l, int r) {
	// �¿���һ����ʱ����
	int *t = new int(r);
	// �ݹ������[l,r]���䣬����������������
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
