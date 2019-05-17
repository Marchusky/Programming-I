#include <iostream>

class Tree
{
public:
	~Tree()
	{
		clear(root);
	}
	void printInorder()
	{
		printInorderRec(root);
	}
	void clear(Node *n)
	{
		if (n != nullptr)
		{
			clear(n->left);
			clear(n->right);
			delete n;
		}
	}
	void insert(int value)
	{
		if (vacio)
		{
			
		}
		else
		{
			insertRec(value, root);
		}
	}
private:
	struct Node
	{
		int value;
		Node *left = nullptr;
		Node *right = nullptr;
	};
	Node *root = nullptr;
	void printInorderRec(Node *n)
	{
		if (n != nullptr)
		{
			printInorderRec(n->left);
			printInorderRec(n->right);
			std::cout << n->value << " - ";
		}
	}
	void insertRec(int value, Node *n)
	{
		//lo de mas pequeño mas grande
	}
};