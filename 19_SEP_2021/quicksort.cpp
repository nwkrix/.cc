#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int partition(vector<int>& arr, int lo, int hi){
	int pivot = arr[(lo+hi)/2];
	int i = lo - 1, j = hi + 1; // typically lo = 0, hi arr.size()-1
	while(1){
		do{
			i++;
		}while(arr[i] < pivot);
		do{
			j--;
		}while(arr[j] > pivot);
		if(i >= j)
			return j;
		swap(arr[i],arr[j]);
	}
}
void quicksort(std::vector<int>& arr,int lo, int hi){
	if(lo < hi){
		int j = partition(arr,lo,hi);
		quicksort(arr,lo,j);
		quicksort(arr,j+1,hi);
	}
}

int main(){
	vector<int> vec{67,56,29,18,14,88,12,99,87}; int lo = 0, hi = vec.size()-1;
	quicksort(vec,lo,hi);
	for(int i : vec){cout << i << ", ";} cout << endl;
	return 0;
}