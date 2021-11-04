#include<iostream>
using namespace std;
auto Swap = [](int& a,int& b){int tmp = a; a = b; b = tmp;};
void i_sort(int a[],int len){ // insertion sort
	for(int i = 0; i < len; i++ ){
		for(int  j = i+1; j < len; j++){
			if(a[i] > a[j]){
				 ::Swap(a[i],a[j]);
			}
		}
	}
}

void print(int a[],int len){
	for(int i=0;i<len;i++){
		cout << a[i] << ", ";
	}
	cout << endl;
}

int main(){
	int arr[]{10,18,9,6,15,4,7,11,10}, len = *(&arr + 1)-arr;
	//cout << selection(arr,len,5) << endl;
	i_sort(arr,len);
	print(arr,len);
	return 0;
}