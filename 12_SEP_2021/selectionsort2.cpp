#include<iostream>
using namespace std;
auto Swap=[](int& a,int& b){int tmp=a;a=b;b=tmp;};
int selection(int a[], int lo, int hi){
	int idx=lo,min=a[idx];
	for(int i=lo;i<hi;i++){
		if(a[i]<min)min=a[i],idx=i;
	}
	return idx;
}
void sort(int a[], int len){
	int j, tmp;
	for(int i=0;i<len;i++){
		j = selection(a,i,len);
		::Swap(a[i],a[j]);
	}
}
void display(int a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << ", ";
	}cout << endl;
}
int main() {
	int a[]{ 38,19,90,100,16,102,18,56,99,7 };
	int len = *(&a + 1) - a;
	sort(a,len);
	display(a,len);
	return 0;
}