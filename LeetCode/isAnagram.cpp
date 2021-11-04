#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end()); 
        sort(t.begin(), t.end());
        size_t len = s.size(), len2 = t.size();
        if(len != len2) return false;
        for(int i = 0; i < len; i++){
            if(s[i]!=t[i]) return false;
        }

        return true;
    }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        int count_s[26] = {0};
        
        for (int i = 0; i < s.length(); i++)
            count_s[s[i] - 'a']++;
        
        for (int i = 0; i < t.length(); i++) {
            count_s[t[i] - 'a']--;
            
            if(count_s[t[i] - 'a'] < 0)
                return false;
        }
        
        for (auto i : count_s)
            if (i != 0)
                return false;
        
        return true;
    }
    
};

int main(){
    string s = "anagram", t = "nagaram";
    Solution l;
    cout << l.isAnagram(s,t) << endl;
    return 0;
}