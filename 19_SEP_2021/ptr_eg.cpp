#include<iostream>
#include<memory>

using namespace std;
struct Node {
	int val;
	shared_ptr<Node> next = nullptr;

	Node() : val(-1), next(nullptr) {}
	Node(int a) : val(a), next(nullptr) {}
	Node(int a, shared_ptr<Node> next ) : val(a), next(next) {}
	~Node() {
		cout << "ptr deleted " << endl;
	}

	/* shared_ptr<Node>*ptr == Node** For this, parse append(&head), given that head is a pointer
	  shared_ptr<Node>&ptr == Node*& For this, parse append(head), given that head is a pointer	*/
	
	shared_ptr<Node> newNode(int val){
		shared_ptr<Node> node = make_unique<Node>();
		node->val = val, node->next = nullptr;
		return node;
	}

	void append(int val,shared_ptr<Node>&ptr) 
	{
		if(!ptr){ // i.e. if (ptr == NULL)
			ptr = newNode(val);
			return;
		}
		shared_ptr<Node> current = ptr;
		while(current->next){
			current = current->next;
		}
		current->next = newNode(val);
	}
	shared_ptr<Node> preprend(int val, shared_ptr<Node>ptr){
		if(!ptr){
			return newNode(val);
		}
		shared_ptr<Node> node = newNode(val);
		node->next = ptr;
		ptr = node;
		return ptr;
	}
	void remove(int val,shared_ptr<Node>&ptr){
		if(!ptr){
			return;
		}
		shared_ptr<Node> current = ptr, prev = ptr;
		while(current && current->val != val){
			prev = current;
			current = current->next;
		}
		if(!current){
			cout << "Item not found" << endl;
		}else{
			if(current == ptr)
				ptr = ptr->next;
			if(!current->next){
				prev->next = nullptr;
			}else{
				prev->next = current->next;
			}
		}
	}

};

int main()
{
	//shared_ptr<Node> head = make_unique<Node>();
	//shared_ptr<Node> head = make_unique<Node>(10);
	shared_ptr<Node> head = make_unique<Node>(9,make_unique<Node>(10,make_unique<Node>(19,nullptr)));
	
	Node l;
	l.append(21,head);
	head = l.preprend(-18,head);
	l.remove(-18,head);
	while(head){
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}