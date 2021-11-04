#include<iostream>
#define DIM1 3 
#define DIM2 3
#define DIM3 5
using namespace std;
int* one_d(){
	int *arr = new int[DIM1];
	for(int i=0; i < DIM1; i++){
		arr[i] = 2 * (i+1) - i * i;
	}
	return arr;
}
void print1d(int *a){
	for(int i = 0; i < DIM1; i++){
		cout << *(a+i) << ", ";
	}
	cout << endl;
}
void deallocate1d(int *ptr){
	delete[] ptr; ptr = NULL; // the loop depth where the word "new" appears determines if loop is used for deallocation or not
}
int** two_d(){
	int** arr = new int*[DIM1];
	for(int i = 0; i < DIM1; i++){
		arr[i] = new int[DIM2];
	}
	for(int i = 0; i < DIM1; i++){
		for(int j = 0; j < DIM2; j++)
			arr[i][j] = 2 * (j + 1) - j * j;
	}
	return arr;
}
void print2d(int** ptr){
	for(int i = 0; i < DIM1; i++){
		for(int j = 0; j < DIM2; j++)
			cout << ptr[i][j] << ", ";
		cout << endl;
	}
}
void deallocate2d(int** ptr){
	for(int i = 0; i < DIM1; i++){
		delete[] ptr[i];
	}
	delete[] ptr;
	ptr = NULL;
}

int*** three_d(){
	int*** arr = new int**[DIM1];
	for(int i = 0; i < DIM1; i++){
		arr[i] = new int*[DIM2];
		for(int j = 0; j < DIM2; j++){
			arr[i][j] = new int[DIM3];
		} 
	}
	for (int i = 0; i < DIM1; i++){
		for(int j = 0; j < DIM2; j++){
			for(int k = 0; k < DIM3; k++){
					arr[i][j][k] = (1+i)*(1-j)*(k+2)- i*j*k;
			}
		}
	}
	return arr;
}
void print3d(int*** a){
	for (int i = 0; i < DIM1; i++){
		cout << "DIM " << i << "\n";
		for(int j = 0; j < DIM2; j++){
			for(int k = 0; k < DIM3; k++){
				cout << a[i][j][k] << ", " ;
			}
			cout << "\n";
		}
	}
}
void deallocate3d(int ***ptr){
	for(int i = 0; i < DIM1; i++){
		for(int j = 0; j < DIM2; j++){
			delete[] ptr[i][j];
		} 
		delete[] ptr[i];
	}
	delete[] ptr;
	ptr = NULL;
}

int main()
{
	int *ptr = one_d(); print1d(ptr); deallocate1d(ptr);
	cout << endl;
	int **ptr2 = two_d(); print2d(ptr2); deallocate2d(ptr2);
	int*** ptr3 = three_d(); print3d(ptr3); deallocate3d(ptr3);
	return 0;
}