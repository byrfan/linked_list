#include "llist.hpp"

int main() {
	Node* head = create_list(2); // create new list, heads value is 2
	append(head, 4); // append a new node with the value of 4
	append(head, 5); // append a new node with the value of 5
	head = push(head, 1); // push a new node to the start wwith the value of 1
	insert_at_pos(head, 2, 3); // insert a new node at pos 2 with the value of 3

	print_list(head); // prints the list
}
