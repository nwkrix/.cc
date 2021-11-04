#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    // finds the insection of two arrays
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output; int intersecting; map<int, bool> seen; map<int, int>seen_freq;
        for (int i : nums1) {
            if (seen[i]) {
                seen_freq[i]++;
            }
            if (!seen[i]) {
                seen[i] = true;
                seen_freq[i] = 1;
            }
            intersecting = chk_in_nums2(i, seen_freq[i],nums2);
            if (intersecting) {
                output.push_back(i);
            }
        }
        return output;
    }
    bool chk_in_nums2(int i, int seen_freq, const vector<int> nums2) {
        map<int, bool> SEEN; map<int, int> SEEN_FREQ;
        for (int j : nums2) {
            if (SEEN[j]) {
                SEEN_FREQ[j]++;
            }
            if (!SEEN[j]) {
                SEEN[j] = true;
                SEEN_FREQ[j] = 1;
            }
            if (i == j && seen_freq == SEEN_FREQ[j]) {
                return true;
            }
        }
        return false;
    }
    
};
int main(){
    Solution l;
    vector<int> u = { 4,9,5,4}, w = { 9,4,9,8,4 };
    //vector<int> u = {1,2,2,1}, w = {2,2};
    vector<int> v = l.intersect(u,w);
    for(int i : v){
        cout << i << ", ";
    }cout << endl;
    return 0;
}