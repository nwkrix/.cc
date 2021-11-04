#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
void wordfreq()
{
	std::fstream file("file.txt", std::ios::in);
	if(!file.is_open()){
		std::cerr << "File access failed" << std::endl;
		exit(1);
	}

	struct wf{
		string word;
		int freq;
	};
	
	auto display = [](vector<wf> v){
		for(wf i : v){
		cout << "{" << i.word << " : " << i.freq << "}\n ";
		}
	};
	auto already_stored = [](string incoming_word, vector<wf>& dict){
		size_t len = dict.size();
		for(int i = 0; i < len; i++){
			if(incoming_word == dict[i].word){ // == for string, const char* strncmp
				return i;
			}
		}
		return -1;
	};
	string incoming_word;
	wf s; // [word|freq] item to be insert in dict 
	vector<wf> dict;
	int location; // locaion in dict whr word existed
	while(file >> incoming_word){
		transform(incoming_word.begin(), incoming_word.end(),
					incoming_word.begin(), ::toupper); 
		s.word  = incoming_word;
		s.freq = 0;
		location = already_stored(incoming_word, dict);
		if(location < 0){
			s.freq += 1;
			dict.push_back(s);
		}else {
			++dict[location].freq; // to the location, increment freq 
		}
	}
	display(dict);
}

int main()
{
	wordfreq();
	return 0;
}