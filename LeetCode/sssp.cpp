#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<limits.h>
#define START 'A'
#define END 'F'
std::map<char,bool> visited;
std::map<char,int> Dist;
class Solution{
public:
	/*Output is cost (int) of shortest path & the path vector<char> 
	  Input should be the graph, start_node and destination node
	*/
	std::map<char,char> ssspath(std::map<char,std::list<std::pair<char,int>>>& graph, char source, char destination){	
		for(char i = START; i <= END; i++){
			Dist[i] = INT_MAX;
			visited[i] = false;
		}
		Dist[source] = 0;
		auto comparison = [](std::pair<char,int> bots, std::pair<char,int> tops){
			return tops.first < bots.first;
		};
		std::priority_queue<std::pair<char,int>,std::vector<std::pair<char,int>>,decltype(comparison)> q(comparison);
		q.push(std::make_pair(source,Dist[source]));
		std::pair<char,int> src;
		while(!q.empty()){
			src = q.top();
			q.pop();
			if(visited[src.first]) continue;
			visited[src.first] = true;
			if(visited[destination]){
				// src.second would be incorrect since cost is updated only in Dist[]
				pathcost = Dist[src.first]; 
				break;
			}
			for(std::pair<char,int> w : graph[src.first]){
				if(Dist[w.first] > w.second + Dist[src.first]){
					Dist[w.first] = w.second + Dist[src.first]; 
					// whereever possible use the distance from Dist[]
					prev[w.first] = src.first;
				}
				q.push(std::make_pair(w.first,Dist[w.first]));
			}
			
		}
		return prev;
	}
	void show_path(std::map<char,char> p){reconstructPath(p);}
private:
	std::map<char,char> path;
	int pathcost;
	std::map<char,char> prev;

	void reconstructPath(std::map<char,char> prev){
		std::map<char,char> :: iterator it = prev.begin();
		while(it!=prev.end()){
			std::cout << it->first << "->" << it->second << std::endl;
			it++;
		}
	}
};
int main(){
	Solution l;
	std::map<char,std::list<std::pair<char,int>>> adj;
	adj['A'] = {{'B',1},{'C',3}};
	adj['B'] = {{'D',1},{'C',2}};
	adj['C'] = {{'D',1},{'F',5}};
	adj['D'] = {{'E',1}};
	adj['E'] = {{'F',5}};
	adj['F'] = {};
	l.show_path(l.ssspath(adj,'A','D'));
	return 0;
}