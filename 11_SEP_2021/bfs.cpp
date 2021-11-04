#include<iostream>
#include<list>
#include<string>
#include<map>
using namespace std;
map<char,list<char> > adjlist;
map<char, bool> visited;
class firstSearch {
public:
	void addNode(char vertex, list<char> neighbor) {
		for(char w: neighbor)
			adjlist[vertex].push_back(w);
	}
	void dfs(char src) {
		visited[src] = true;
		cout << src << ", ";
		for (char w : adjlist[src]) {
			if (!visited[w]) {
				visited[w] = true;
				dfs(w);
			}
		}
	}

	list<char> queue;
	void bfs(char src) {
		queue.push_back(src); // Oh, someone joins the queue
		visited[src] = true; // well, you're first in the queue, the receptionist visits u
		while (!queue.empty()) { // while customers enqueu to take their rooms
			char v = queue.front(); // receptionists will take them out of the queue on a first come first serve basis
			cout << v << ", "; // The director is watching, so be of good behavior
			queue.pop_front(); // A receptionist : "I just took her away from the queue to attend to her needs"
			for (char neighbor : adjlist[v]) { // she likes to visit her neighbors in the other rooms
				if (!visited[neighbor]) { // if you weren't visited
					visited[neighbor] = true; // she just did. Happy now?
					queue.push_back(neighbor); // you too can now visit your other neighbors;
				}
			}
		}

	}
};

int main() {
	firstSearch g;
	g.addNode('A', {'B','E'});
	g.addNode('B', {'C','D','E'});
	g.addNode('C', { });
	g.addNode('D',{'C'});
	g.addNode('E', {'C'});
	//g.bfs('A');
	g.dfs('B');
	return 0;
}