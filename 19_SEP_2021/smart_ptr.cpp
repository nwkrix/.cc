#include<iostream>
#include<memory>
using namespace std;
struct Node{
	int val;
	shared_ptr<Node> next;
	Node() : val(-1), next(nullptr) {}
	Node(int val) : val(val), next(nullptr) {}
	Node(int val, std::weak_ptr<Node> next) : val(val), next(next) {}
};


void compute(int len)
{
	unique_ptr<int[]> p = make_unique<int[]>(len);
	for(int i=0; i < len; i++){
		p[i] = (i==0) ? 1 : i * p[i-1];
	}
	for(int i = 0; i < len; i++){
		cout << p[i] << ", ";
	}cout << endl;
}

void see(){
	unique_ptr<int> p = make_unique<int>(200);
	*p = 10;
	cout << *p << endl;
}

int main(){
	compute(5);
	see();
	return 0;
}