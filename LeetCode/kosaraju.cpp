#include<iostream>
#include<list>
#include<map>
#define START 'A'
#define END 'I'
std::map<char,bool> visited;
class Solution{
public:
	std::list<std::list<char>> kosaraju_algo(std::map<char,std::list<char>>& gragh, char src){
		std::list<char> staque = dfs(src,gragh);
		this->reset_visited();
		reversed_graph = reversed(gragh);
		while(!staque.empty()){
			src = staque.back();
			staque.pop_back();
			if(visited[src]) continue;
			tmp.clear();
			tmp = dfs(src,reversed_graph);
			scc.push_back(tmp);
		}
		return scc;

	}
	void printgraph(std::map<char, std::list<char>>& m){Printgraph(m);}
	void printscc(const std::list<std::list<char>>& m){ PrintSCC(m);}
private:
	std::list<char> tmp;
	std::list<std::list<char>> scc;
	std::map<char, std::list<char>> reversed_graph;
	std::list<char> dfs(char src,std::map<char,std::list<char>>& gragh){
		visited[src] = true;
		for(char w : gragh[src]){
			if(!visited[w])
				dfs(w,gragh);
		}
		tmp.push_back(src);
		return tmp;
	}
	std::map<char,std::list<char>> reversed(std::map<char,std::list<char>>& gragh){
		for(int i = START; i <= END; i++){
			for(char w : gragh[i])
				reversed_graph[w].push_back(i);
		}
		return reversed_graph;
	}
	void reset_visited(){
		for(char i = START; i <= END; i++){
			visited[i] = false;
		}
	}
	void Printgraph(std::map<char,std::list<char>>& m){
		std::map<char,std::list<char>> :: iterator it = m.begin();
		while(it!=m.end()){
			std::cout << it->first << " -> { ";
			for(char w : it->second){
				std::cout << w << " ";
			}std::cout << "}" << std::endl;
			it++;
		}
	}
	void PrintSCC(const std::list<std::list<char>>& m){
		for(std::list<char> l : m){
			for(char w : l){
				std::cout << w << " ";
			}std::cout << std::endl;
		}
	}
};
int main()
{
	std::map<char,std::list<char>> adj;
	/*adj['A'] = {'B'};
	adj['B'] = {'D'};
	adj['C'] = {'A'};
	adj['D'] = {'C','H'};
	adj['E'] = {'D','G'};
	adj['F'] = {'E','G','I'};
	adj['G'] = {};
	adj['H'] = {'F','I'};
	adj['I'] = {};*/
	adj['A'] = {'B'};
    adj['B'] = {'C'};
    adj['C'] = { 'A','D' };
    adj['D'] = {'E'};
    adj['E'] = {'F'};
    adj['F'] = {'G'};
    adj['G'] = {'E'};
    adj['H'] = {'D','F'};
	Solution l;
	std::cout << " ::: GRAPH ::: \n";
	l.printgraph(adj);
	std::cout << " ::: STRONGLY CONNECTED COMPONENTS ::: \n";
	l.printscc(l.kosaraju_algo(adj,'A'));
	return 0;
}