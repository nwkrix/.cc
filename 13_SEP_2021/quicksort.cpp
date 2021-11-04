#include<iostream>
using namespace std;
int partition(int a[],int lo,int hi){
	int pivot = a[(lo+hi)/2];
	int i = lo-1,j = hi+1;
	while(true){
		do{
			i++;
		}while(a[i] < pivot);
		do{
			j--;
		}while(a[j] > pivot);
		if(i>=j) return j;
		int tmp=a[i]; a[i]=a[j]; a[j]=tmp;
	}
}
void quicksort(int a[],int lo, int hi){
	if(lo<hi){
		int j = partition(a,lo,hi);
		quicksort(a,lo,j);
		quicksort(a,j+1,hi);
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
	quicksort(a, 0, len - 1);// lo = 0, hi = len-1
	display(a, len);
	return 0;
}