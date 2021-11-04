#include<iostream>
using namespace std;
auto Swap = [](int& a, int& b){int tmp = a; a = b; b = tmp;};
int partition(int lo, int hi, int a[]){
	int pivot = a[lo];
	int i = lo - 1;
	int j = hi + 1;
	while(true){
		do{
			i++;
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		if(i >= j) return j;
		::Swap(a[i],a[j]);
	}
}
void quicksort(int lo, int hi, int a[]){
	if(lo < hi){
		int j = partition(lo,hi,a);
		quicksort(lo,j,a);
		quicksort(j+1,hi,a);
	}
}
void print(int a[], int len){for(int i=0;i<len;i++){cout << a[i] << ", " ;}cout << endl;}
int main(){
	int a[]{124,100,111,19,35,45,900,88,66,500,423};
	int len = *(&a+1)-a;
	quicksort(0,len-1,a);	
	print(a,len);
	return 0;
}