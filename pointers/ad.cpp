#include<iostream>
using namespace std;
int main()
{
    int a[2];;
    int *p = &a[0]; int *q = &a[1];
    int **pp = &p;
    cout << pp << "\n";
    cout << q << "\n";
    return 0;
}