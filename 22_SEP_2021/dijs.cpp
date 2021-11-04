#include<iostream>
#include<limits.h>
#include<unordered_map>
#include<list>
#include<utility>
#include<queue>
using namespace std;

unordered_map<char,list<std::pair<char,int>> >Adjlist; // 'currNode' => {{'B',cost},{},...}
unordered_map<char,int>Dist; // node, cost - pair
unordered_map<char,char> Via;
unordered_map<char,bool>Visited;

struct gNode{
	char Node;
	double cost; // can also use instead of std::pair<char,double>
};

#define GSIZE 'E'

void graph(char node, list<std::pair<char,int>> neighbor){
	for(std::pair<char,int>& i : neighbor){
		Adjlist[node].push_back(i);  
	}
}

void dijkstra(char src){
	for(char i = 'A'; i<=GSIZE; i++){
		Dist[i] = INT_MAX;
		Visited[i] = false;
	}
	Dist[src] = 0; 
	auto cmp = [](std::pair<char,int> Bots, 
		std::pair<char,int> Tops)
	{
		return (Tops.second < Bots.second);
	};
	priority_queue <std::pair<char,int>,
	vector<std::pair<char,int>>, decltype(cmp)> q (cmp);
	q.push({src,Dist[src]});
	while(!q.empty()){
		src = q.top().first;
		q.pop();
		for(std::pair<char,int>& w : Adjlist[src]){
			if(Visited[w.first]) continue;
			if(w.second + Dist[src] < Dist[w.first]){
				Dist[w.first] = w.second + Dist[src];
				Via[src] = w.first;
			}
			q.push({w.first,Dist[w.first]});
		}
		Visited[src] = true;
	}
	
}
void print(){
	unordered_map<char,int>::iterator it = Dist.begin();
	cout << " :: COST :: " << endl; 
	while(it != Dist.end() ){
		cout << it->first << " : " << it->second << endl;
		it++;
	}
	cout << " :: PATH :: " << endl;
	unordered_map<char,char> :: iterator itr = Via.begin();
	while(itr!=Via.end()){
		cout << itr->first << " -> " << itr->second << endl;
		itr++;
	}
}

int main(){
	graph('A',{ {'B',6},{'D',1} });
	graph('B',{ {'A',6},{'D',2},{'E',2},{'C',5} });
	graph('C',{ {'B',5},{'E',5} });
	graph('D',{ {'A',1},{'B',2},{'E',1} });
	graph('E',{ {'B',2},{'D',1},{'C',5} });
	dijkstra('A');
	print();
	return 0;
}