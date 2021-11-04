#include<iostream>
using namespace std;
auto swap = [](int& a, int& b) { int tmp = a; a = b; b = tmp; };
void heapify(int* a, int len, int root) {
	int leftChild = 2 * root + 1, rightChild = 2 * root + 2, moving_root = root;
	if (leftChild < len && a[leftChild] > a[moving_root])
		moving_root = leftChild;
	if (rightChild < len && a[rightChild] > a[moving_root])
		moving_root = rightChild;
	if (moving_root != root) {
		::swap(a[moving_root],a[root]);
		heapify(a,len,moving_root);
	}
}
void build_heap(int arr[], int len) {
	for (int i = (len / 2) - 1; i >= 0; i--) {
		heapify(arr, len, i);
	}
}

void heapsort(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		build_heap(arr, len - i);
		::swap(arr[0], arr[len - (1+i)]);
	}
}


int main() {
	int arr[]{ 2,59,49,3,84,87,78,23,93,36,37,15,19 };
	//const int len = sizeof(arr) / sizeof(arr[0]);
	const int len = *(&arr + 1) - arr;
	heapsort(arr,len);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ", ";
	}cout << endl;
	return 0;
}