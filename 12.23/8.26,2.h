#include <iostream>

using namespace std;

char ch;
int cnt;

struct btnd{
	char name;
	int l,r;
};

void btcpy(btnd bt1[],btnd bt2[],int l){
	for(int i = 0;i < l;i++){
		bt1[i].name = bt2[i].name;
		bt1[i].l = bt2[i].l;
		bt1[i].r = bt2[i].r;
	}
}

int bbt(int bt,btnd btre[]){
	cin >> ch;
	if(ch == '.'){
		bt = 0;
		return bt;
	}else{
		bt = ++cnt;
		btre[bt].name = ch;
		btre[bt].l = btre[bt].r = 0;
		btre[bt].l = bbt(bt,btre);
		btre[bt].r = bbt(bt,btre);
	}
	return bt;
}

void out3(int bt,btnd btr[]){
	if(bt){
		out3(btr[bt].l,btr);
		out3(btr[bt].r,btr);
		cout << btr[bt].name;
	}
	
}

void out1(int bt,btnd btr[]){
	if(bt){
		cout << btr[bt].name;
		out1(btr[bt].l,btr);
		out1(btr[bt].r,btr);
		
	}
}

void out2(int bt,btnd btr[]){
	if(bt){
		out2(btr[bt].l,btr);
		cout << btr[bt].name;
		out2(btr[bt].r,btr);
		
	}
}
