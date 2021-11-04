#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        size_t len = s.size(); char ch;
        std::map<char, bool> seen;
        std::map<char, int> seen_freq;

        for (int i = 0; i < len; i++) {
            if(seen[s[i]])
                seen_freq[s[i]]++;
            if (!seen[s[i]])
                seen[s[i]] = true, seen_freq[s[i]] = 1;
        }
        for(int i = 0; i < len; i++){
            if(seen_freq[s[i]] == 1)
                return i;
        }
        return -1;
    }

      int firstUniqChar(string s) {
        int ans[26] = {0};
        
        for(int i=0; i<s.size(); i++){
            ans[s[i] - 'a']++;
        }
        for(int i=0; i<s.size(); i++){
            if(ans[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }

    
};
int main() {
    Solution l;
    string s = "zleetcodze";
    cout << l.firstUniqChar(s) << endl;
    return 0;
}