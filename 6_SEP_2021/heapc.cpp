#include<iostream>
using namespace std;
void heapify(int a[], const int len, int root){
    int leftc = 2 * root, rightc = 2 * root + 1, current = root;
    if(leftc <= len && a[leftc] > a[current])
        current = leftc;
    if(rightc <= len && a[rightc] > a[current])
        current = rightc;
    auto swap = [](int& a, int& b){a = a + b; b = a - b; a = a - b;};
    if(current != root){
        swap(a[root], a[current]);
        heapify(a, len, current);
    }
}
void build_heap(int a[], int len){
    for(int i = len/2; i > 0; i--){
        heapify(a, len, i);
    }
}
int main()
{
    int a[]{0, 2,41,5,66,90,23,18,36,19}; const int len = *(&a+1)-a;
    build_heap(a, len);
    for(int i = 1; i < len; i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}