#include<iostream>
using namespace std;
auto Swap = [](int& a,int& b){int tmp = a; a = b; b = tmp;};
int selection(int a[], int len, int start){
	int min;
	if(start < len){
		 min = a[start];
		for(int i=start; i < len; i++)
			if(a[i] < min) {min = a[i]; start = i;};
	}
	return start;
}
void sort(int a[], int len){
	for(int i = 0; i < len; i++){
		int j = selection(a,len,i);
		::Swap(a[i],a[j]);
	}
}
void print(int a[],int len){
	for(int i=0;i<len;i++){
		cout << a[i] << ", ";
	}
	cout << endl;
}

int main()
{
	int arr[]{10,18,9,6,15,4,7,11,10}, len = *(&arr + 1)-arr;
	//cout << selection(arr,len,5) << endl;
	sort(arr,len);
	print(arr,len);
	return 0;
}