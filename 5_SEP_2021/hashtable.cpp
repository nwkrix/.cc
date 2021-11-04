#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define T_SIZE 5
#define MAXLEN_NAME 128
#define CITIMAX 128
struct state { // data for the hash table
	unsigned int id;
	char city[CITIMAX];
	char governor[MAXLEN_NAME];
};
struct Node { // linkedlist for external chaining
	state* data;
	Node* link;
};
class linkedlist {
	Node* root; // local root
	Node* newNode(state* data) { 
		Node* node = new Node();
		node->data = data;
		node->link = NULL;
		return node;
	}
public:
	linkedlist() {
		root = NULL;
	}
	void append(Node** external_root, state *s) { // append for hash table receives exernal root:= *Table[i]
		if (*external_root == NULL) {
			*external_root = newNode(s);
			return;
		}
		Node* last = *external_root;
		while (last->link != NULL) {
			last = last->link;
		}
		last->link = newNode(s);
	}
	void remove(Node** external_root, state* s){
		if(external_root == NULL) return;
		Node *current = *external_root, *previous = NULL;
		while(current->link != NULL && strcmp(current->data->city, s->city) != 0 && 
			strcmp(current->data->governor, s->governor) != 0){
				previous = current;
				current = current->link;
		}
		if(previous == NULL){ // the loop wasn't entered
			*external_root = current->link; // deletes the root 
		}else{
			previous->link = current->link;
			delete current; current = NULL;
		}
	}
	bool search(Node** external_root, state *s){
		if(*external_root == NULL) return false;
		Node* current = *external_root;
		while(current != NULL){
			if(strcmp(s->city,current->data->city)==0 && strcmp(current->data->governor,s->governor)==0){
				return true;
			}
			current = current->link;
		}
		return false;
	}
	
};
class HashT : public linkedlist {
	Node* Table[T_SIZE];
public:
	HashT() {
		for (int i = 0; i < T_SIZE; i++) {
			Table[i] = NULL; // roots of linked list
		}
	}
	bool isEmpty() { for (int i = 0; i < T_SIZE; i++) { if (Table[i] != nullptr) return false; } return true; }
	unsigned int hashfcn(const char* city) {
		size_t len = strnlen(city, CITIMAX);
		unsigned int hashvalue = 0;
		for (int i = 0; i < len; i++) {
			hashvalue += city[i];
			hashvalue = hashvalue * city[i];
		}
		return hashvalue % T_SIZE;
	}
	void insert(state* s) {
		if (s == NULL) return;
		unsigned int key = hashfcn(s->city);
		append(&Table[key],s); // append 1st arg takes in ptr-2-ptr, so I parse in address of ptr-Table to be modified by it
	}
	void remove(state *s){
		if(s == NULL) return;
		unsigned int key = hashfcn(s->city);
		linkedlist::remove(&Table[key],s);
	}
	bool search(state* s){
		if(s == NULL) return false;
		unsigned int key = hashfcn(s->city);
		return linkedlist::search(&Table[key],s);
	}
	
	void display() {
		for (int i = 0; i < T_SIZE; i++) {
			if (Table[i] == NULL) {
				printf("%i\t%s\t%s\n", i, "___", "___");
				continue;
			}
			Node* last = Table[i];
			printf("%i", i);
			while (last != NULL) {
				printf("\t%s\t%s\t%%", last->data->city, last->data->governor);
				last = last->link;
			}
			cout << endl;
		}
	}
};
int main()
{
	HashT t;
	state df = { 1, "Mexico City, DF", "Obara Dor" };
	state oa = { 2, "Oaxaca", "Lopez Diego" };
	state mt = { 3, "Monterrey", "Gonzalez Emilia" }; 
	state xo = { 4, "Xochimilco", "Sol Isabel" };
	state ja = { 5, "Jalisco","Jessica S" };
	state ac = { 6, "Acapulco","David V" };
	state ca = { 7, "Cancun","Chris N" };
	state te = { 8, "Teotihuacán","Cleopatra Eg" };
	state mo = { 9, "Morelos","Humberto P" };
	state ba = { 10, "Baja California","Mary T" };
	t.insert(&df);
	t.insert(&oa);
	t.insert(&mt);
	t.insert(&xo);
	t.insert(&ja);
	t.insert(&ac);
	t.insert(&ca);
	t.insert(&te);
	t.insert(&mo);
	t.insert(&ba);	
	
	// delete from Hash Table
	//t.remove(&ba);
	//t.remove(&mo);
	
	t.display(); 
	
	cout << t.search(&ba) << "\n"; // 1 if found, 0 otherwise
	
	return 0;
}