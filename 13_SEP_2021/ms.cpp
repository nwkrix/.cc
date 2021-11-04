// C++ program for Merge Sort
#include <iostream>
using namespace std;
void merge(int array[], int const left, int const mid, int const right)
{
	auto const len_l = mid - left + 1;
	auto const len_r = right - mid;

	
	auto *arr_l = new int[len_l],
		*arr_r = new int[len_r];


	for (auto i = 0; i < len_l; i++)
		arr_l[i] = array[left + i];
	for (auto j = 0; j < len_r; j++)
		arr_r[j] = array[mid + 1 + j];

	auto i = 0, 
		j = 0; 
	int k = left; 

	// Merge the temp arrays back into array[left..right]
	while (i < len_l && j < len_r) {
		if (arr_l[i] <= arr_r[j]) {
			array[k] = arr_l[i];
			i++;
		}
		else {
			array[k] = arr_r[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (i < len_l) {
		array[k] = arr_l[i];
		i++;
		k++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (j < len_r) {
		array[k] = arr_r[j];
		j++;
		k++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursivly

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}
