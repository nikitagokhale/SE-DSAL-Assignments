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
	Node *parent;
	Node *child;
	Node *root;
	Node *traverse;

	TBT()
	{
		head = nullptr;
		parent = nullptr;
		child = nullptr;
		root = nullptr;
		traverse = nullptr;
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
			createSubTree(traverse->left);
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
			createSubTree(traverse->right);
		}
		return traverse;
	}

	Node *inorder(Node *traverse)
	{
		while(traverse->lflag)
			traverse = traverse->left;

		while(traverse!=head)
		{
			cout<<traverse->data<<" ";
			traverse = traverse->right;
			while(traverse->lflag)
				traverse = traverse->left;
		}

		return root;
	}
};

int main()
{
	TBT tree;
	int choice;
	while (choice != 7)
	{
		cout << "\n*************START*************";
		cout << "\nMAIN MENU\n1. Create TBT.\n";
		cout << "Enter your choice:- ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			tree.root = tree.create(tree.root);
			break;

		case 2:
			tree.root = tree.inorder(tree.root);
			break;

		default:
			cout << "Please enter a valid choice!";
			break;
		}
		cout << "\n**************END**************\n\n";
	}

	return 0;
}
