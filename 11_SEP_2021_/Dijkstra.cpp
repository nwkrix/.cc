#include<iostream>
#include<limits>
#include<map>
#include<list>
#include<queue>
using namespace std;
struct gNode {// A node on a graph & the cost of an edge leaving the node
	char node;
	double cost;
};
map<char, double> Dist;
map<char, bool> Visited;
map<char, char>Via; // keeps track of the node that leads to the current node, Via[Parent] = Child
map<char, list<gNode>> Alist;
class Dijks {
	int number_of_nodes;
public:
	Dijks() {
		number_of_nodes = 0;
	}
	Dijks(int number_of_nodes) {
		this->number_of_nodes = number_of_nodes;
	}
	void addNode(char node, list<gNode> neighbor) {
		for (gNode& i : neighbor) {
			Alist[node].push_back(i);
		}
	}
	void DijksPath(char src) { // enter a node as given in the Adjacency list
		for (char i = 'A'; i <= char(int('A') + number_of_nodes - 1); i++) { // internally labeling nodes with English Alphabets
			Dist[i] = numeric_limits<double> ::infinity();
			Visited[i] = false;
		}
		Dist[src] = 0; // src-to-src costs zero
		auto some_rule = [](gNode& Bot, gNode& Top) {
			return (Top.cost < Bot.cost);
		};
		priority_queue<gNode, vector<gNode>, decltype(some_rule)> q(some_rule);
		q.push({ src,Dist[src] }); // push in the first gNode element
		while (!q.empty()) {
			src = q.top().node;
			q.pop();
			for (gNode& w : Alist[src]) {
				if (Visited[w.node]) continue;
				if (Dist[w.node] > Dist[src] + w.cost) { // checking the initialized (wild) gues of inf ... 
					Dist[w.node] = Dist[src] + w.cost; // ... or of poor route against calculated (updated)values
					Via[src] = w.node; // best path from src to w.node
					q.push(w);
				}
			}
			Visited[src] = true;
		}
	}
	void print() {
		map<char, double> ::iterator it;
		cout << "\tNode" << "   " << "Cost" << endl;
		for (it = Dist.begin(); it != Dist.end(); it++) {
			cout <<"\t" <<it->first << "      " << it->second << endl;
		}
		cout << "\t:: Path ::" << endl;
		for (map<char, char> ::iterator it = Via.begin();
			it != Via.end(); it++) {
			cout <<"\t"<< it->first << "  ->  " << it->second << endl;
		}
	}
};


int main() {
	Dijks d(5);
	d.addNode('A', { {'B',6},{'D',1} });
	d.addNode('B', { {'A',6},{'D',2},{'C',5},{'E',2} });
	d.addNode('C', { {'B',5},{'E',5} });
	d.addNode('D', { {'B',2},{'A',1},{'E',1} });
	d.addNode('E', { {'D',1},{'C',5},{'B',2} });
	d.DijksPath('A');
	d.print();
	return 0;
}