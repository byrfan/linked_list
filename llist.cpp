#include <iostream>
#include "llist.hpp"

class Node { //definition for Node
	public:
		int data; // public data
	Node* next; // private next node
};

Node* create_list(int p) { // this method returns one node, the "head" of the list
	Node* head = NULL;
	head = new Node();
	head->data = p;
	head->next = NULL;
	return head;
}

void print_list(Node* n) { // print all nodes in the list out
	while(n!=NULL) {
		std::cout<<n->data<<" ";
		n = n->next;
	}
}

Node* get_tail(Node* n) { // returns the "tail" of the list
	while(true) {
		if(n->next!=NULL) {
			n = n->next;
		}else {
			break;
		}
		
	}
	return n;
}

void insert_at_pos(Node* n, int p, int m) { // insert data at a specific point in the list like C arrays,
	/*                                [0][1][2][3]
	 * for example in the C array i = {1, 3, 4, 5};   
	 * this would be the same in the list
	 * so to insert a new node with the value of 2 in pos 1 we would pass in:
	 *            [node][pos][val]
	 * insert_at_pos(head, 1, 2)
	 * 
	 * we would then have i = {1, 2, 3, 4, 5};
	 * 
	 * */
	if(p==0) {
		throw std::invalid_argument("Cannot insert to beginning...use push()");
	}
	Node* n_prev = NULL; // prev node (before the incersion point)
	Node* n_next = NULL; // next node (after the incersion point)
	n_prev = new Node();
	n_next = new Node();
	for(int i=0; i<=p+1; i++) { // traversing through the list
		if(n->next!=NULL) { // if the next node is not equal to NULL
			if(i==p-1) {  // will only do this the node before the pos
				n_prev = n;
			}else if(i==p+1) { // will only do this the node after the pos
				n_next = n;
			}else { // does this every other time
				n = n->next;
			}
		}else {
			throw std::invalid_argument("Cannot insert to end...use append()");
		}
	}
	Node* current = NULL;
	current = new Node();
	current->data = m;
	current->next = n_next;
	n_prev->next = current;
}
//          [head]      [val]
void append(Node* n, int m) { // this function appends to the end of the list
	n = get_tail(n);
	Node* current = NULL;
	current = new Node();
	current->data = m;
	current->next = NULL;
	n->next = current;	
}
//        [head]      [val]
Node* push(Node* n, int m) { // this function pushes to the front of the list and returns a new head
	Node* current = NULL;
	current = new Node();
	current->data = m;
	current->next = n;
	return current; // new head for the list
}
