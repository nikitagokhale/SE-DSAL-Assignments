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
	int data, lbit, rbit;
	Node *left;
	Node *right;

public:
	Node(int data = 0, int lbit = 0, int rbit = 0)
	{
		this->data = data;
		this->lbit = lbit;
		this->rbit = rbit;
		left = nullptr;
		right = nullptr;
	}

	friend class BT;
};

class Stack
{

};

class BT
{
	Node *head;
	Node *parent;
	Node *child;
	Node *root;
	Node *traverse;

public:
	BT()
	{
		head = nullptr;
		parent = nullptr;
		child = nullptr;
		root = nullptr;
		traverse = nullptr;
	}

	Node *insert(Node *traverse, int &ref_data)
	{
		int data;

		if(head == nullptr)
		{
			Node *head = new Node();
			head->left = head;
			head->right = head;
			head->lbit = 1;
			head->rbit = 1;
		}

		if(head->data == 0)
		{
			traverse = new Node();
			head->left = traverse;
			traverse->data = ref_data;
			head->data++;
			traverse->left = traverse;
			traverse->right = traverse;
			root = traverse;
			return traverse;
		}

		if(traverse == nullptr)
		{
		    traverse = new Node();
		    traverse->data = ref_data;
		    head->data++;
		    traverse = find_inorder_succ_pred(traverse);
		    return traverse;
		}

		if(ref_data > traverse->data)
		{
			traverse->right = insert(traverse->right, ref_data);
			return traverse;
		}

		traverse->left = insert(traverse->left, ref_data);
		return traverse;
	}

	Node *find_inorder_succ_pred(Node *traverse)
	{

	}
};

int main()
{
    BT tree;
    int choice, data
    while(choice != 7)
    {
        cout<<"\n*************START*************";
        cout<<"\nMAIN MENU\n1. Insert Node.\n";
        cout<<"Enter your choice:- ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 1:
            cout<<"Enter the data:- ";
            cin>>data;
            tree.root = tree.insert(tree.root, data);
        	break;

        default:
            cout<<"Please enter a valid choice!";
            break;
        }
        cout<<"\n**************END**************\n\n";
    }

    return 0;
}
