#include<iostream>
#include<cstring>
#define T_SIZE 10
#define EMAX 128
#define SCHMAX 128
using namespace std;
struct Data {
	const char schName[SCHMAX];
	unsigned int strNUm;
	const char strName[128];
	const char Princial[100];
	const char email[EMAX];
	unsigned int year;
};
struct Node{
	Data* sch;
	struct Node* link;
};
class LinkedList {
	Node* internal_root; // can be used on the class independdent of the class children
	Node* newNode(Data* s) {
		Node* node = new Node();
		node->sch = s; node->link = NULL;
		return node;
	}
public:
	void append(Data* s, Node** ext_root) {
		if (s == NULL) return;
		if (*ext_root == NULL) {
			*ext_root = newNode(s);  // O(1) at this point (insertion)
			return;
		}
		Node* last = *ext_root;
		while (last->link != NULL) { // a little more work in ...
			last = last->link;     // in the event of a collision
		}
		last->link = newNode(s);
	}
	bool search(Node** root, Data* s) {
		if (*root == NULL) return false; // s not yet in table
		if (*root != NULL && strncmp((*root)->sch->email, // O(1) at this point
			s->email, EMAX) == 0) return true; //found at the head of LL
		Node* iter = *root;
		while (iter->link != NULL && strncmp(iter->link->sch->email,
			s->email, EMAX) != 0) { // A little more work to ...
			iter = iter->link;      // accomodate possible collisions
		}
		if (iter->link == NULL) return false; // got to end, not found
		return true; //[FOUND] down the linked list. Loop broke by strncmp
	}
	void del(Node* root) { delete root; root = NULL; }

	void remove(Data* s, Node** ext_root) {
		if (*ext_root == NULL) return;
		if (*ext_root != NULL && strncmp((*ext_root)->sch->email,
			s->email, EMAX) == 0) {
			*ext_root = (*ext_root)->link;
			return;
		}
		Node* iter = *ext_root;
		while (iter->link != NULL) {
			if (strncmp(iter->link->sch->email, s->email, EMAX) == 0) {
				iter->link = iter->link->link;
				return;
			}
			iter = iter->link;
		}
	}

};
class Hasht : public LinkedList {
	Node* Table[T_SIZE]; // Table is of Node type. It cantains data (contains sch data)
public:
	void remove(Data* s) { // to remove, first task: locate "i.e. search", what to remove
		unsigned int key = hashfcn(s->email);
		LinkedList::remove(s, &Table[key]); // parse in address of item to be removed
	}
	bool search(Data* s) {
		unsigned int key = hashfcn(s->email);
		return LinkedList::search(&Table[key], s); // users don't have to bother about d table
	}
	void insert(Data* s) {
		unsigned int key = hashfcn(s->email);
		append(s, &Table[key]); // parse in a pointer's address
	}
	unsigned int hashfcn(const char email[]) {
		size_t len = strnlen(email, EMAX);
		unsigned int hashval = 0;
		for (unsigned int i = 0; i < len; i++) {
			hashval += email[i];
			hashval *= email[i];
		}
		return hashval % T_SIZE;
	}
	Hasht() {
		for (int i = 0; i < T_SIZE; i++) {
			Table[i] = NULL; // array of pointers
		}
	}
	bool isEmpty() const {
		for (int i = 0; i < T_SIZE; i++) {
			if (Table[i] != NULL) return false;
		}
		return true;
	}
	void display() const {
		if (this->isEmpty()) return;
		Node* iter; // for reassigning Table[i] so d fcn dont modify it
		for (int i = 0; i < T_SIZE; i++) {
			if (Table[i] == NULL) continue;
			printf("%i ", i);
			iter = Table[i];
			while (iter != NULL) {
				printf("\t%s,|\t%i|\t%s,|\t%s,|\t%s,|\t%i",
					iter->sch->schName, iter->sch->strNUm,
					iter->sch->strName, iter->sch->Princial,
					iter->sch->email, iter->sch->year);
				iter = iter->link;
				//Table[i] = Table[i]->link;//[WARNING] can modify d table forall next fcns
				printf("\n");
			}
		}
	}
};

int main()
{
	Hasht t;
	Data sch1 = { "Little Caezars Academy", 43, "Moon Crescent Abuja",
				"Joyce Akhigbe", "caezars@little.edu",1887 };
	Data sch2 = { "Kings College", 1002, "Goive High Altitute",
				"Tochukwu Uchegbu", "info@goive.edu.ng",1901 };
	Data sch3 = { "University of Lagos", 4020, "Diplomatic Drive Aso",
				"Kenny Bush", "uni@lag.edu",1801 };
	Data sch4 = { "COMSATS University", 128, "Eagle Square Islamabad",
				"Taj Salim", "comsats@edu.edu.pk",1991 };
	Data sch5 = { "Insituto Politécnico Nacional", 1888, "Zacatenco Madrid",
				"Claudio Gonzales", "universidad@ipn.mx",1884 };
	Data sch6 = { " UNAM ", 1200, "Avenida Aeropuerto",
				"Obra Dores", "unive@autonoma.mx",1766 };
	t.insert(&sch1); t.insert(&sch2); t.insert(&sch3); t.insert(&sch4);
	t.insert(&sch5);
	t.display();
	t.remove(&sch2);
	t.display();
	cout << t.search(&sch2) << endl;
	return 0;
}