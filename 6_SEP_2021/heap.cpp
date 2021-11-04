#include<iostream>
using namespace std;
void heapify(int a[], int len, int root)
{
    int left_child = 2 * root + 1, right_child = 2 * root + 2, parent = root;
    if (left_child < len && a[left_child] > a[parent])
        parent = left_child;
    if (right_child < len && a[right_child] > a[parent])
        parent = right_child;
    if (parent != root) {
        swap(a[parent], a[root]);
        heapify(a, len, parent);
    }
}
void build_heap(int a[], int len)
{
    for (int i = (len/2)-1; i >= 0; i--) {
        heapify(a, len, i);
    }
}
void heapsort(int a[], int len)
{
	for(int i=0; i < len; i++){
		build_heap(a,len-i);
		swap(a[0],a[len-(1+i)]);
	}
}
int main()
{
    int a[]{ 900,132,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,24 };
	const int len = *(&a + 1) - a;
    heapsort(a, len);
    for (int i = 0; i < len; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}