#include<iostream>
#include<string>
bool isPalindrome(std::string s){
	size_t len = s.size();
	if(len==1) return true;
	int i = 0, j = len-1;
	while(i < j){
		if(s[i]!=s[j])
			return false;
		i++, j--;
	}
	return true;
}
bool isPalindrome2(const std::string& s){
	if(s.size() < 2) return true;
	size_t len = s.size();
	if(s[0]==s[len-1])
		return isPalindrome2(s.substr(1,len-1-1));
	return false;
}


int main(){
	std::string s = "RACECAR";
	//s = s.substr(0,2);
	//std::cout << s << std::endl;
	std::cout << isPalindrome(s) << std::endl;
	return 0;
}