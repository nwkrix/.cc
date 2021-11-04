#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0;
    std::priority_queue<int,std::vector<int>,std::greater<int>> q; 
    while(i < m){
        q.push(nums1[i]);
        i++;
    }
    i = 0;
    while(i<n){
        q.push(nums2[i]);
        i++;
    }
    i = 0;
    while( !q.empty() ){
        nums1[i] = q.top();
        i++;
        q.pop();
    }        
}
int main(){
    vector<int> a = {2,6,8,0,0,0}, b = {1,2,3};
    merge(a,3,b,3);
    for(int i : a) {cout << i << ", ";}; cout << endl;
    return 0;
}