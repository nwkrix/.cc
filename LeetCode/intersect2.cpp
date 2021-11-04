#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    // finds the insection of two arrays
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        const int len1 = nums1.size(); const int len2 = nums2.size();
        vector<int> output;
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (nums1[i] == nums2[j]) {
                output.push_back(nums1[i]);
                i++, j++;
            }
            if (nums1[i] < nums2[j]) {
                i++;
            }
            if (nums1[i] > nums2[j]) {
                j++;
            }
        }
        return output;
    }
  
    
};
int main(){
    Solution l;
    vector<int> u = { 4,9,5,4}, w = { 9,4,9,8,4 }; // {4,4,5,8}, {4,4,8,9,9}
    //vector<int> u = {1,2,2,1}, w = {2,2};
    vector<int> v = l.intersect(u,w);
    for(int i : v){
        cout << i << ", ";
    }cout << endl;
    return 0;
}