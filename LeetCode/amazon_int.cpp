#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
class Amazon_int{
public:
	void freq_in_string(std::string&& str){
		for(int i=0; i<str.size();i++){
			m[str[i]]++;
		}
		std::map<char,int> :: iterator it = m.begin();
		while(it!=m.end()){
			vp.push_back(std::make_pair(it->first,it->second));
			it++;
		}

		std::sort(vp.begin(),vp.end(),std::greater<int>());
	}
private:
	std::map<char,int> m;
	std::vector<std::pair<char,int>> vp;
};
int main(){
	Amazon_int l;
	l.freq_in_string("CASSABLANKA");
	return 0;
}