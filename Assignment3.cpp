//============================================================================
// Name        : Assignment3.cpp
// Author      : Nikita Gokhale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
public:
	int data, lflag, rflag;
	Node *left;
	Node *right;

	Node(int data = 0, int lflag = 0, int rflag = 0)
	{
		this->data = data;
		this->lflag = lflag;
		this->rflag = rflag;
		left = nullptr;
		right = nullptr;
	}
	friend class TBT;
};

class TBT
{
public:
	Node *head;
	Node *root;

	TBT()
	{
		head = nullptr;
		root = nullptr;
	}

	Node *create(Node *traverse)
	{
		if (root == nullptr)
		{
			traverse = new Node();
			head = new Node();
			root = traverse;
			head->left = traverse;
			head->right = head;
			traverse->left = traverse->right = head;
			cout<<"Enter data for root node:- ";
			cin>>traverse->data;
			traverse = createSubTree(traverse);
			return traverse;
		}
		else
		{
			cout<<"Tree is already created!";
			return root;
		}
	}

	Node *createSubTree(Node *traverse)
	{
		int flag;
		cout << "Create left sub tree for node " << traverse->data << "? Enter 0/1:- ";
		cin >> flag;
		if (flag)
		{
			Node *temp = new Node();
			temp->left = traverse->left;
			temp->right = traverse;
			traverse->left = temp;
			traverse->lflag = 1;
			cout<<"Enter the data:- ";
			cin>>temp->data;
			traverse->left = createSubTree(traverse->left);
		}
		cout << "Create right sub tree for node " << traverse->data<< "? Enter 0/1:- ";
		cin >> flag;
		if (flag)
		{
			Node *temp = new Node();
			temp->left = traverse;
			temp->right = traverse->right;
			traverse->right = temp;
			traverse->rflag = 1;
			cout<<"Enter the data:- ";
			cin>>temp->data;
			traverse->right = createSubTree(traverse->right);
		}
		return traverse;
	}

	Node *inorder(Node *traverse)
	{
		while (traverse != head)
		{
			while (traverse->lflag == 1)
				traverse  = traverse->left;

			cout<< traverse->data<< " " ;

			while (traverse->rflag == 0)
			{
				traverse  = traverse->right;
				if (traverse  == head)
					return traverse;
				cout<< traverse->data<< " " ;
			}
			traverse = traverse->right;
		}
		cout<<"Tree is empty!";
		return nullptr;
	}

	Node *preorder(Node *traverse)
	{
		while (traverse != head)
		{
			cout<< traverse->data<< " " ;
			while (traverse->lflag == 1)
			{
				traverse  = traverse->left;
				cout<< traverse->data<< " " ;
			}

			while (traverse->rflag == 0)
			{
				traverse  = traverse->right;
				if (traverse  == head)
					return traverse;
			}
			traverse = traverse->right;
		}
		cout<<"Tree is empty!";
		return nullptr;
	}
};

int main()
{
	TBT tree;
	int choice;
	while (choice != 7)
	{
		cout << "\n*************START*************";
		cout << "\nMAIN MENU\n1. Create TBT.\n2. Inorder traversal.\n3. Preorder traversal.\n7. Exit.\n";
		cout << "Enter your choice:- ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			tree.root = tree.create(tree.root);
			break;

		case 2:
			tree.head = tree.inorder(tree.root);
			break;

		case 3:
			tree.head = tree.preorder(tree.root);
			break;

		case 7:
			cout<<"Thank you!";
			break;

		default:
			cout << "Please enter a valid choice!";
			break;
		}
		cout << "\n**************END**************\n\n";
	}
	return 0;
}
