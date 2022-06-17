#include "llist.hpp"

int main() {
	Node* head = create_list(2);
	append(head, 4);
	append(head, 5);
	head = push(head, 1);
	insert_at_pos(head, 2, 3);
	
	//append(head, 10);
	//head = push(head, 2);
	print_list(head);
}
