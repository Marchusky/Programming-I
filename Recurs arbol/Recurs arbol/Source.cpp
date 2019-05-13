#include <iostream>


struct Node {
	int value = 0;
	Node *left = nullptr;
	Node *right = nullptr;
};

void print_tree_pre_order(Node *n) {
	if (n != nullptr) {
		print_tree_pre_order(n->left);
		std::cout << n->value << " - ";
		print_tree_pre_order(n->right);

	}
}
void print_tree_in_order(Node *n) {
	if (n != nullptr) {
		std::cout << n->value << " - ";
		print_tree_in_order(n->left);
		print_tree_in_order(n->right);

	}
}

void print_tree_post_order(Node *n) {
	if (n != nullptr) {
		print_tree_post_order(n->right);
		std::cout << n->value << " - ";
		print_tree_post_order(n->left);
	}
}

int main() {

	Node *a = new Node; a->value = 3;
	Node *b = new Node; b->value = 4;
	Node *c = new Node; c->value = 5;
	Node *d = new Node; d->value = 6;
	Node *e = new Node; e->value = 10;
	Node *f = new Node; f->value = 0;
	Node *g = new Node; g->value = 2;
	 
	a->left = b;
	a->right = e;
	b->left = c;
	b->right = d;
	e->left = f;
	e->right = g;

	print_tree_pre_order(a);
	std::cout << "\n" << std::endl;
	print_tree_in_order(a);
	std::cout << "\n" << std::endl;
	print_tree_post_order(a);
	std::cout << "\n" << std::endl;





	system("pause");
	return 0;
}