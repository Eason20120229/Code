#include <iostream>
#include <algorithm>
using namespace std;
struct one{
	string name;
	int month;
	int day;
};
bool cmp1(one a = new one("") ,one b){return a.month < b.month;}
bool cmp2(one a,one b){return a.day < b.day;}
int main(){
	int n;
	one o[100];
	cin >> n;
	for(int i = 0;i < n;i++) cin >> o[i].name >> o[i].month >> o[i].day;
	sort(o,o + n,cmp2);
	sort(o,o + n,cmp1);
	cout << o[0].name  << " "<< o[n - 1].name;
	return 0;
}
