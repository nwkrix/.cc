#include<iostream>
using namespace std;
struct Node {
	Node* link;
	int data;
};
class linkedlist {
	Node *head;
	Node* newnode(int data)
	{
		Node* new_node = new Node(); new_node->data = data; new_node->link = NULL;
		return new_node;
	}
public:
	linkedlist()
	{
		head = NULL;
	}
	~linkedlist() //delete this
	{}
	void append(int data)
	{
		if (head == NULL) {
			head = newnode(data);
			return;
		}
		else {
			Node* currentLast = head;
			while (currentLast->link != NULL)
			{
				currentLast = currentLast->link;
			}
			currentLast->link = newnode(data);
		}
	}

	void prepend(int data)
	{
		if (head == NULL) {
			head = newnode(data);
		}
		else {
			Node* current = newnode(data);
			current->link = head;
			head = current;
			
		}
	}
	int size() const
	{
		int count = 0;
		if (head == NULL) return count;
		Node* current = head; 
		while (current != NULL)
		{
			count++;
			current = current->link;
		}
		return count;
	}
	void reverse_slow ()
	{
		int len = this->size(); 
		if (len == 0) {
			cout << " List is empty ";
			return;
		}
		int* arr = new int[len];
		Node* current = head; int idx = len-1;
		while (current != NULL)
		{
			arr[idx] = current->data; idx--;
			current = current->link;
		}
		current = head; idx = 0;
		while (current != NULL)
		{
			current->data = arr[idx]; idx++;
			current = current->link;
		}
	}
	void reverse()
	{
		Node* temp = head;
		Node* nextnode = NULL;
		Node* revnode = NULL;
		while (temp != NULL) {
			head = temp;
			nextnode = temp->link;
			temp->link = revnode;
			revnode = temp;
			temp = nextnode;
		}
	}
	void print() const
	{
		if (head == NULL)
		{
			cout << "Empty Node \n" << endl;
			return;
		}
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << ", ";
			current = current->link;
		}
		cout << endl;
	}
};

int main()
{
	linkedlist *h = new linkedlist;
	h->print();
	h->append(3); h->append(4); h->append(5);
	h->print();
	h->prepend(0); h->prepend(-8);
	h->print();
	cout << h->size() << "\n";
	h->reverse();
	h->print();
	delete h; h = NULL;
	return 0;
}