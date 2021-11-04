#include<iostream>
using namespace std;
auto Swap = [](int& a, int& b){int tmp = a; a = b; b = tmp;};
int selection(int a[], int len, int start){
	int min = a[start];
	for(int i = start; i < len; i++){
		if(a[i] < min) {min = a[i]; start = i;}
	}
	return start;
}
void sort_now(int a[],int len){
	for(int i = 0; i < len; i++){
		int j = selection(a, len, i);
		::Swap(a[i],a[j]);
	}
}
void print(int a[], int len){for(int i=0;i<len;i++){cout << a[i] << ", " ;}cout << endl;}
int main(int argc, char const *argv[])
{
	int a[]{124,100,111,19,35,45,900,88,66,500,423};
	int len = *(&a+1)-a;
	sort_now(a,len);
	print(a,len);
	return 0;
}