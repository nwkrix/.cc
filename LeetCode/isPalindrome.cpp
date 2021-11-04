#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
    	string c = ",: ";
        //for (char i : c ){s.erase(std::remove(s.begin(), s.end(),i),s.end());s.erase(std::remove(s.begin(), s.end(),' '),s.end()); // this removes specified char, but not all}

        auto notEnglishChar = [](char i){return !isalnum(i); };
       s.erase(remove_if( s.begin(),s.end(),notEnglishChar),s.end() ); // removes all non-English char
       //s.erase(remove_if(s.begin(),s.end(),[](char i){return !isalpha(i)||isdigit(i);}),s.end());
        int i = 0, j = s.size()-1;
        while(i < j ){
        	if(toupper(s[i]) != toupper(s[j])){
        		return false;
        	}
        	i++, j--;
        }
        return true;
    }


     bool isPalindrome_my_sol(string s) {
        s.erase(remove_if(s.begin(),s.end(),[](char i){return !isalnum(i);}),s.end());
        int i = 0, j = s.length()-1;
        while(i < j){
            if(toupper(s[i])!=toupper(s[j])) return false;
            i++, j--;
        }
        return true;        
    }

    bool isPalindrome2(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (!isalnum(s[l])) l++;
            else if (!isalnum(s[r])) r--;
            else if (tolower(s[l]) != tolower(s[r])) return false;
            else l++, r--;
        }
        return true;
    }
};
using namespace std;
int main(){
	//string s =  "A man, a plan, a canal: Panama";
	//string s = "Marge, let's \"[went].\" I await {news} telegram.";
	//string s = "race a car";
	string s = "####Madam####";
	Solution l;
	cout << l.isPalindrome_my_sol(s) << endl;
	return 0;
}