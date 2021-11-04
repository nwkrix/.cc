#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* next = NULL;
};
class linkedlist{
	Node* rootptr;
	Node* newNode(int a){
		Node* node = new Node(); node->data = a; node->next = NULL;
		return node;
	}
public:
	Node* getroot(){
		return this->rootptr;
	}
	linkedlist(){
		rootptr = NULL;
	}
	bool isEmpty(){
		return (rootptr == NULL);
	}

	void Append(int& info){ // Append(Node** root, Info& info)
		if(this->isEmpty()){
			rootptr = newNode(info);
			return;
		}
		Node* last = rootptr;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = newNode(info);
	}
	void Prepend(int info){
		if(this->isEmpty()){
			rootptr = newNode(info);
			return;
		}
		Node* n = newNode(info);
		n->next = rootptr;
		rootptr = n;
	}
	int min(int a[], int len){
		int min = a[0];
		for(int i = 1; i < len; i++){ if(a[i] < min) min = a[i];} return min;
	}
	// Merging (unsorted) k sorted linked list into one obj
	void sort(Node* root1, Node* root2, Node* root3){ // use getroot() to assign the *rootptr to each class obj
		while(root1 != NULL){
			this->Append(root1->data); root1 = root1->next;
		}
		while(root2 != NULL){
			this->Append(root2->data); root2 = root2->next;
		}
		while(root3 != NULL){
			this->Append(root3->data); root3 = root3->next;
		}
	}


	// using priority queue to sort & merge k sorted linked list
	void sort2(linkedlist& l1, linkedlist& l2,  linkedlist& l3){
		auto cmp = [](Node Bots,Node Tops){return (Tops.data < Bots.data);};
		priority_queue <Node, vector<Node>, decltype(cmp)> q(cmp);

		while(l1.rootptr != NULL){
			q.push(*l1.rootptr); l1.rootptr = l1.rootptr->next;
		}
		while(l2.rootptr != NULL){
			q.push(*l2.rootptr); l2.rootptr = l2.rootptr->next; 
		}
		while(l3.rootptr != NULL){
			q.push(*l3.rootptr); l3.rootptr = l3.rootptr->next;
		}
		while(!q.empty()){
			cout << q.top().data << ", ";
			q.pop();
		}
	}

	// using min heap to merge k sorted linked list
	void merge_sort_k_sorted_list(linkedlist& l1, linkedlist& l2, linkedlist& l3){
		auto heapify = [](int a[], int len, int root){
			int left_child = 2*root + 1, right_child = 2*root + 2, parent = root;
			if(left_child < len && a[left_child] > a[parent])
				parent = left_child;
			if(right_child < len && a[right_child] > a[parent])
				parent = right_child;
			if(root != parent){
				int tmp = a[root]; a[root] = a[parent]; a[parent] = tmp;
			}
		};
		auto build_heap = [&heapify](int a[], int len){
			for(int i = (len/2); i>=0; i--){
				heapify(a,len,i);
			}
		};

		int* arr;
		int i = 0;
		while(l1.rootptr != NULL){
			arr[i] = l1.rootptr->data; i++; l1.rootptr = l1.rootptr->next;
		}
		while(l2.rootptr != NULL){
			arr[i] = l2.rootptr->data; i++; l2.rootptr = l2.rootptr->next;
		}
		while(l3.rootptr != NULL){
			arr[i] = l3.rootptr->data; i++; l3.rootptr = l3.rootptr->next;
		}
		auto Swap = [](int& a, int& b) {int tmp = a; a = b; b = tmp;};
		auto heapsort = [&build_heap,&Swap](int a[],int len){
			for(int i = 0; i < len; i++){
				build_heap(a,len-i);
				Swap(a[0],a[len-1-i]);
			}
		};
		heapsort(arr,i);
		for(int k = 0; k < i; k++){
			cout << arr[k] << ", " << endl;
		}cout << endl;
	}
// reverse linked
	void reverse(){
		Node *previous = NULL, 
			 *current = this->rootptr, 
			 *ahead = NULL;
		while(current !=NULL){
			ahead = current->next;
			current->next = previous;
			previous = current;
			current = ahead;
		}
		this->rootptr = previous;
	}
// print the middle element of a linked list
	int printmid(){
		Node* fast = this->rootptr, *slow = this->rootptr;
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow =slow->next;
		}
		return slow->data;
	}
	void display(){
		Node* current = this->rootptr;
		while(current != NULL){
			cout << current->data << ", ";
			current = current->next;
		}cout << endl;
	}
};
int main(){
	linkedlist l1 = linkedlist();
	for(int i=34; i < 42; i++){
		l1.Prepend(4*i-2*i);
	}   
	l1.display();
	linkedlist l2 = linkedlist();
	l1.reverse();
	cout << l1.printmid() << endl;
	l1.display();
	return 0;
}