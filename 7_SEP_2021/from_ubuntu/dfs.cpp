#include<iostream>
#include<list>
#include<map>
using namespace std;
class Graph {
	map<int, list<int>> adj;
	map<int, bool> visited;
	map<int, bool> visitedd;
public:
	void addNode(int vertex, list<int> neighbor) {
		for (int i : neighbor) {
			adj[vertex].push_back(i);
		}
	}
	void dfs(int v) {
		visited[v] = true;
		cout << v << ", ";
		for (int w : this->adj[v]) {
			if (!visited[w]) {
				dfs(w);
			}
		}
	}
	list<int> queue;
	void bfs(int v) { 
		visitedd[v] = true;
		queue.push_back(v);
		while (!queue.empty()) {
			v = queue.front();
			cout << v << ", ";
			queue.pop_front();	
			for (int w : adj[v]) {
				if (!visitedd[w]) {
					visitedd[w] = true;
					queue.push_back(w);
				}
			}
		}

	}

};
/*
procedure DFS(G, v) is
label v as discovered
for all directed edges from v to w that are in G.adjacentEdges(v) do
if vertex w is not labeled as discovered then
recursively call DFS(G, w)
*/




int main() {
	Graph g;
	g.addNode(0, { 1,2,4});
	g.addNode(1, {2,3});
	g.addNode(2, {0,1});
	g.addNode(3, {});
	g.addNode(4, {1,4});
	g.dfs(0);
	cout << endl;
	g.bfs(0);
	return 0;
}