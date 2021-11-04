#include<iostream>
using namespace std;
void merge(int lo, int mid, int hi, int a[]){
	

	for(int i = mid; i < hi; i++){
		cout << a[i] << ",";
	}cout << endl;
}
void mergesort(int lo, int hi, int a[]){
	if(lo < hi){
		int mid = (lo+hi)/2;
		mergesort(lo,mid,a);
		mergesort(mid+1,hi,a);
		merge(lo,mid,hi,a);
	}
}
int main(){
	int a[]{3,4,2,1};
	int len = *(&a+1)-a;
	mergesort(0, len, a);
	return 0;
}