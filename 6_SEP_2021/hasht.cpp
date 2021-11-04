#include<iostream>
#include<cstring>
#define EMAX 255
#define T_SIZE 10
using namespace std;
// data to store in hash table
struct amazon_employee{
	unsigned int id;
	const char name[100];
	const char email[EMAX];
};
struct Node{
	amazon_employee * data;
	Node* link;
};
class LinkedList{
	Node* root;
	Node* newNode(amazon_employee* s){
		Node* node = new Node();
		node->data = s; node->link = NULL;
		return node;
	}
public:
	void append(amazon_employee* s, Node** ext_root ){
		if( *ext_root == NULL){
			*ext_root = newNode(s);
			return;
		}
		Node* last = *ext_root;
		while(last->link != NULL){
			last = last->link;
		}
		last->link = newNode(s);
	}
	
};
class Hasht : public LinkedList{
	Node* Table[T_SIZE]; // Table[i] a node of a linked list
public:
	void insert(amazon_employee* s){
		unsigned int key = hashfcn(s->email);
		append(s,&Table[key]); // table parsed by reference
	}
	Hasht(){
		for(int i = 0; i < T_SIZE; i++){
			Table[i] = NULL;
		}
	}
	bool isEmpty(){
		for(int i = 0; i < T_SIZE; i++){
			if(Table[i] != NULL) return true;
		}
		return false;
	}
	unsigned int hashfcn(const char* email){
		size_t len = strnlen(email,EMAX); 
		unsigned int hashNum = 0;
		for(int i = 0; i < len; i++){
			hashNum += email[i];
			hashNum *= email[i]; 
		}
		return hashNum % T_SIZE;
	}
	
	bool search(const char* email){
		
	}
	void remove(const char* email){
		
	}
	void display(){
		for(int i=0; i<T_SIZE;i++){
			if(Table[i]!=NULL){
				Node* last = Table[i];
				printf("\t%i ",i);
				while(last!=NULL){
					printf("\t%s\t%s ",Table[i]->data->name,Table[i]->data->email);
					last = last->link;
				}
				printf("\n");
			}
		}
	}
};

int main()
{
	Hasht t;
	amazon_employee e1 = {231, "Hector David","dav@amazon.com"};
	amazon_employee e2 = {231, "Hector David","dav@amazon.com"};
	amazon_employee e3 = {231, "Hector David","dav@amazon.com"};
	amazon_employee e4 = {231, "Hector David","dav@amazon.com"};
	
	amazon_employee e5 = {231, "Hector David","david@amazon.com"};
	amazon_employee e6 = {9090, "Ken G J","nwkrix@gmail.com"};
	
	t.insert(&e1); t.insert(&e2);
	t.insert(&e3); t.insert(&e4);
	t.insert(&e5); t.insert(&e6);
	//t.remove(e1.email);
	t.display();
	//cout << t.search(e1.email) << endl;
	return 0;
}