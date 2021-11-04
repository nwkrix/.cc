#include<iostream>
//#define INT_MAX 2147483647
using namespace std;
auto Swap = [](int& a,int& b){int tmp = a; a = b; b = tmp;};
int partition(int lo, int hi, int arr[]){
	int pivot = arr[lo];
	int i = lo - 1;
	int j = hi + 1;
	while(true){
		do{
			i++;
		}while(arr[i] < pivot);
		do{
			j--;
		}while(arr[j] > pivot);
		if(i >= j){
			return j;
		}
		Swap(arr[i],arr[j]);
	}
}
void quicksort(int lo, int hi, int arr[]){
	if(lo >=0 && hi >=0){
		if(lo < hi){
			int j = partition(lo, hi, arr);
			quicksort(lo,j,arr);
			quicksort(j+1,hi,arr);
		}
	}
}


int main(){
	int arr[]{10,18,9,6,15,4,7,11,10}, len = sizeof(arr)/sizeof(arr[0]);
	//int j = partition(0,len,arr);
	//cout << j << endl;
	quicksort(0,len-1,arr); // len = hi, ensure a[hi] in fcn is within range
	for(int i = 0; i < len; i++)
		cout << arr[i] << ", ";
	cout << endl;
	return 0;
}