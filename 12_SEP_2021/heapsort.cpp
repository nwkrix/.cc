#include<iostream>
using namespace std;
void heapify(int a[],int len,int i){
	int l_child=2*i+1, r_child=2*i+2, root = i;
	if(l_child<len && a[l_child]>a[root])
		root=l_child;
	if(r_child<len && a[r_child]>a[root])
		root=r_child;
	if(root!=i){
		int tmp=a[root]; 
		a[root]=a[i];
		a[i]=tmp;
		heapify(a,len,root);
	}
}
void build_heap(int a[],int len){
	for(int i=len/2;i>=0;i--){
		heapify(a,len,i);
	}
}
void heapsort(int a[], int len){
	int tmp;
	for(int i=0;i<len;i++){
		build_heap(a,len-i);
		tmp = a[0]; a[0] = a[len-i-1], a[len-i-1] = tmp;
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
	heapsort(a,len);// lo = 0, hi = len-1
	display(a, len);
	return 0;
}