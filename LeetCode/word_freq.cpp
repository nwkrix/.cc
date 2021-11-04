#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;
void display(std::map<std::string,int>& s){
    std::map<std::string,int> :: iterator it = s.begin();
    while(it!=s.end()){
        std::cout << "{ " << it->first << ", " << it->second << " }\n";
        it++;
    }std::cout<<std::endl;
}
void wordFrequency(){
	std::fstream file("Text.txt", std::ios::in);
	if (!file.is_open()) {
		printf("File access failed\n");
		exit(1);
	}
	std::map<std::string,int> res;
	std::string incoming_word;
	while (file >> incoming_word) {
        // all toLower so that "The" & "the" for e.g. will not be interpreted as diffrerent words
		transform(incoming_word.begin(),incoming_word.end(),incoming_word.begin(),::tolower);
        incoming_word.erase(std::remove_if(incoming_word.begin(),incoming_word.end(),
        [](char i){return !isalpha(i);}),incoming_word.end());
        res[incoming_word]++;
	}
	display(res);
}
int main(){
	wordFrequency();
	return 0;
}