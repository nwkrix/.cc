#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

std::map<char,int> char_statistics(std::string&& s){ // RVALUES
	std::map<char,int> res;
	s.erase(std::remove_if(s.begin(),s.end(),[](char c){return !isalpha(c);}),s.end());
	size_t len = s.size();
	vector<char> dict;
	for(int i = 0; i < len; i++){
		res[std::toupper(s[i])]++;
	}
	return res;
}

void display(std::map<char,int>&& m){ 
	std::map<char,int> :: iterator it = m.begin();
	while(it!=m.end()){
		std::cout << it->first << " : " << it->second << std::endl;
		it++;
	}
}

int main(){
	display(char_statistics("?Love# #God Almighty You?r Cre=ator_-"));
	return 0;
}