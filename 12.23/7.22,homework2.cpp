#include <iostream>

using namespace std;

void h(int n,int m){
	if(n == 0){
		cout << "����" << m << "ֻѼ��\n";
		return; 
	}
	h(n - 1,(m + 1) * 2);
	cout << "����" << n << "����ׯ��" << m << "ֻѼ��\n";
}

int main(){
	h(7,2);
}
