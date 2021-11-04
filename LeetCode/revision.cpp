#include<iostream>
#include<vector>

struct Node
{
	int val;
	Node* next;
	Node() : val(),next(nullptr){}
	Node(int val) : val(val), next(nullptr) {}
	Node(int val,Node* next) : val(val), next(next) {}
};
std::vector<int> u, v;
class Solution{
public:
	bool hasCycle(Node* ptr){
		Node* slow = ptr, *fast = ptr;
		while(slow && fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)
				return true;
		}
		return false;
	}
	Node* reverse(Node* ptr){
		if(!ptr || !ptr->next)
			return ptr;
		Node* p = reverse(ptr->next);
		ptr->next->next = ptr;
		ptr->next = NULL;
		return p;
	}
	void print(Node* curr){
		//Node* curr = ptr;
		while(curr){
			std::cout << curr->val << ", ";
			curr = curr->next;
		}
	}
};
int main(){
	Solution l;
	Node* n = new Node(1,new Node(2,new Node(3,new Node(4))));
	Node* a = new Node(11);
	a->next = new Node(12), a->next->next = new Node(13), a->next->next->next = new Node(14), a->next->next->next->next = new Node(15);
	a->next->next->next->next->next = a->next->next; // careful, a has cycle
	Node* m = l.reverse(n);
	l.print(m);
	std::cout << std::endl;
	std::cout << l.hasCycle(a) << std::endl;
	return 0;
}
