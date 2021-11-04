#include<iostream>
/*
	Author: C. Nwachioma
*/
using namespace std;
#define l 4
static const int m = 4, n = 4; 
int* one_d(){
	int* p = new int[l];
	for(int i = 0; i < l; i++)
	{
		p[i] =  i + i-(i % 2); 	
	}
	return p;
}
void deallocate1d(int* ptr)
{
	delete [] ptr;
}
void print1d(int *ptr)
{
	for(int i = 0; i < l; i++)
	{
		cout << ptr[i] << ", ";
	}	
	cout << endl<< endl;
}
// START 2D ARRAY
int** two_d()
{
	int** ptr2ptr = new int*[l]; // total of l pointers, each pointing to 1 of l different pointers
	for(int i = 0; i < l; i++)
	{
		ptr2ptr[i] = new int[m];
	}
	for(int i = 0; i < l; i++)
	{
		for(int j = 0; j < m; j++)
		{
			ptr2ptr[i][j] = i + j - (i % 2) - (j % 2);
		}
	}
	return ptr2ptr;
}
void print2d(int** ptr2ptr)
{
	for(int i = 0; i < l; i++)
	{
		for(int j = 0; j < m; j++)
			cout << ptr2ptr[i][j] << ", ";  
		cout << "\n";
	}
	cout << endl << endl;
}
void deallocate2d(int** ptr2ptr)
{
	for(int i = 0; i < l; i++)
	{
		delete [] ptr2ptr[i];
	}
	delete [] ptr2ptr;
	ptr2ptr = NULL;
}

int*** three_d()
{
	int*** ptr = new int**[n];
	for(int i = 0; i < n; i++)
	{
		ptr[i] = new int*[l];
		for(int j = 0; j < l; j++)
		{
			ptr[i][j] = new int[m];
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < l; j++){
			for(int k = 0; k < m; k++)
				ptr[i][j][k] = (i-1) * (2*j-2) * (k-3);
		}
	}
	return ptr;
}

void print3d(int*** ptr)
{	for(int i  = 0; i < n; i++)
	{
		cout << "3rd dim " << i + 1 << ":\n";
		for(int j = 0; j < l; j++)
		{
			for(int k = 0; k < m; k++){
				cout << ptr[i][j][k] << ", ";
			}
			cout << "\n";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void deallocate3d(int*** ptr)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < l; j++)
		{
			delete [] ptr[i][j];
		}
		delete [] ptr[i];
	}
	delete [] ptr;
	ptr = NULL;
}


int main()
{
	int* ptr = one_d();
	print1d(ptr);
	deallocate1d(ptr);
	
	int** ptr2ptr = two_d();
	print2d(ptr2ptr);
	deallocate2d(ptr2ptr);
	
	int*** ptr3 = three_d();
	print3d(ptr3);
	deallocate3d(ptr3);
	return 0;
}