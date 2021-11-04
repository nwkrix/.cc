#include<iostream>
using namespace std;
void merge(int a[],int lo,int mid,int hi){
	int len_l=mid+1-lo;
	int len_r=hi+1-mid-1;
	auto arr_l=new int[len_l], arr_r=new int[len_r];
	for(int i=0;i<len_l;i++)
		arr_l[i] = a[lo+i];
	for(int i=0;i<len_r;i++)
		arr_r[i] = a[mid+1+i];
	int i=0,j=0,k=lo;
	while(i<len_l&&j<len_r){
		if(arr_l[i]<arr_r[j]) 
			a[k] = arr_l[i], i++;
		else
			a[k] = arr_r[j], j++;
		k++;
	}
	while(i<len_l)
		a[k]=arr_l[i],i++,k++;
	while(j<len_r)
		a[k]=arr_r[j],j++,k++;
}
void mergesort(int a[],int lo,int hi){
	if(lo < hi){
		int mid =  (lo+hi)/2;
		mergesort(a,lo,mid);
		mergesort(a,mid+1,hi);
		merge(a,lo,mid,hi);
	}
}
void display(int a[],int len){
	for(int i=0; i<len; i++){
		cout << a[i] << ", ";
	}cout << endl;
}
int main(){
	int a[]{38,19,90,100,16,102,18,56,99,7};
	int len = *(&a+1)-a;
	mergesort(a,0,len-1);// lo = 0, hi = len-1
	display(a,len);
	return 0;
}