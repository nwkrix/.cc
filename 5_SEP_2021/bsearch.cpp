#include<iostream>
using namespace std;
int binary_search(int a[], int L, int R, int search_value){
	int mid = L + (R-L) / 2;
	if(a[mid] == search_value) return mid;
	if(L < R){	
		return a[mid] < search_value ? binary_search(a,mid+1,R,search_value) : binary_search(a,L,mid-1,search_value);
	}
	return -1;
}
int main()
{
	int a[]{1,2,3,4,5,6,7,8,9,10}, L = 0, R = *(&a+1)-a;
	cout << binary_search(a, L, R-1,19) << "\n";
	return 0;
}

/*
SEE ALSO

#include<iostream>
using namespace std;
int binary_search(int a[], int L, int R, int search_value){
	int mid = L + (R-L) / 2;
	if(a[mid] == search_value) return mid;
	if(L < R){
		if( a[mid] < search_value){
			L = mid + 1;
		}else{
			R = mid - 1;
		}	
		return binary_search(a,L,R,search_value);
	}
	return -1;
}

*/