#include<iostream>
#include<string>
#include<limits.h>
#include<map>
#include<list>
int fcn(long long int s){
	if(s > INT_MAX)
		return EXIT_FAILURE;  // opposite EXIT_SUCCESS
	return s; 
}

using namespace std;
int main(){
	string s = "19898999989897687889898023";
	char ss[] = "1989899998 9897687889 898023"; char* pEnd;
	//int a = stoi(s);
	//long long int b = stoull(s);
	//long long unsigned int c = stoull(s);

	//cout << b << endl;
	//cout << c << endl;

	long long unsigned int d1 = strtoull(ss,&pEnd,10);
	long long unsigned int d2 = strtoull(pEnd,&pEnd,10);
	long long unsigned int d3 = strtoull(pEnd,&pEnd,10);
	cout << d1<<d2<<d3<< endl;
	int r = fcn(d1*2);
	cout << r << endl;
	map<char,std::list<std::pair<char,int>>> adj;
	adj['A'] = {{'C',30}};
	for(std::pair<char,int> w: adj['A']){
		cout << w.first << endl;
	}

	return 0;
}