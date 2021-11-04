#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* link;
};
class linkedlist{
		Node* root;
		Node* newNode(int data){
			Node* node = new Node();
			node->data = data; node->link = NULL;
			return node;
		}
	public:
		linkedlist(){ 														// constructor
			root = NULL;
		}
		bool isEmpty() const{ return (root == NULL);} 							// check if linked list is empty
		int nodeCount(){ 													// returns number of nodes
			int count = 0;
			if (this->isEmpty()) return count; // also valid if "root == NULL"
			Node* last = root;
			while(last != NULL){
				count++;
				last = last->link; 
			}
			return count;
		}
		void append(int data){
			if (this->isEmpty()){
				root = newNode(data);
				return;
			}
			Node* last = root;
			while(last->link != NULL){
				last = last->link;
			}
			last->link = newNode(data);		
		}
		
		void print() const{ // using const keyword, I needed to set isEmpty to const too
			if(this->isEmpty()) cout << " *** Empty Linked List ***" << "\n";
			Node* current = root;
			while(current != NULL){
				cout << current->data << ", ";
				current = current->link;
			}
			cout << endl;
		}
		void prepend(int data){
			if(this->isEmpty())
				root = newNode(data);
			Node* current = newNode(data);
			current->link = root;
			root = current;
		}
		void removebyval(int data){
			if(this->isEmpty()) return;
			Node* current = root;
			this->root = NULL;
			while(current != NULL){
				if(data != current->data){
					this->append(current->data); // deleting and re-assigning, not very efficient
				}
				current = current->link;
			}
		}
		void remove2byval(int data){
			if(this->isEmpty()) return;
			Node *current = root, * previous = NULL;
			while(current != NULL && current->data != data){
				previous = current;
				current = current->link;
			}
			if(current == NULL) return;
			if(previous == NULL){
				root = current->link;
				delete current; current = NULL;
			}else{
				previous->link = current->link;
				//delete current; current = NULL;
			}
		}
		bool search(int data){
			if(this->isEmpty()) return false;
			Node* current = root;
			while(current != NULL){
				if(current->data == data)
					return true;
				current = current->link;
			}
			return false;
		}
};

int main(){
	linkedlist l; l.append(3); l.append(8); l.prepend(100);  
	l.append(19); l.append(23); l.prepend(1);
	//linkedlist m; m.print();
	l.remove2byval(298);
	l.print();
	cout << l.nodeCount() << "\n";
	cout << l.search(30)<< "\n";
	return 0;
}