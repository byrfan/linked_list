#include <iostream>
#include "llist.hpp"

class Node {
	public:
		int data;
	Node* next;
};

Node* create_list(int p) {
	Node* head = NULL;
	head = new Node();
	head->data = p;
	head->next = NULL;
	return head;
}

void print_list(Node* n) {
	while(n!=NULL) {
		std::cout<<n->data<<" ";
		n = n->next;
	}
}

Node* get_tail(Node* n) {
	while(true) {
		if(n->next!=NULL) {
			n = n->next;
		}else {
			break;
		}
		
	}
	return n;
}

void insert_at_pos(Node* n, int p, int m) {
	if(p==0) {
		throw std::invalid_argument("Cannot insert to beginning...use push()");
	}
	Node* n_prev = NULL;
	Node* n_next = NULL;
	n_prev = new Node();
	n_next = new Node();
	for(int i=0; i<=p+1; i++) { // traversing through the list
		if(n->next!=NULL) { // if the next node is not equal to NULL
			if(i==p-1) { // if the current node is equal to 
				n_prev = n;
			}else if(i==p+1) {
				n_next = n;
			}else {
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

void append(Node* n, int m) {
	n = get_tail(n);
	Node* current = NULL;
	current = new Node();
	current->data = m;
	current->next = NULL;
	n->next = current;	
}

Node* push(Node* n, int m) {
	Node* current = NULL;
	current = new Node();
	current->data = m;
	current->next = n;
	return current; // new head for the list
}
