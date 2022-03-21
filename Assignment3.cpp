//============================================================================
// Name        : Assignment3.cpp
// Author      : Nikita Gokhale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : Assignment_3_TBT.cpp
// Author      : Ruturaj Sanjay Ghatage
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 Create an inordered threaded binary tree and perform inorder and preorder traversals. Analyze time and space complexity of the algorithm.
 */

#include <iostream>

using namespace std;

class Node {
private:
	int data;
	bool l_bit, r_bit;
	Node *left_child, *right_child;

public:
	Node() {
		data = '0';
		l_bit = 0;
		r_bit = 0;
		left_child = NULL;
		right_child = NULL;
	}

	Node(int data) {
		this->data = data;
		this->l_bit = 0;
		this->r_bit = 0;
		this->right_child = NULL;
		this->left_child = NULL;
	}

	friend class TBT;
};

class TBT {
private:
	Node *head;
	Node *root;

public:
	TBT() {
		head = NULL;
		root = NULL;
	}

	Node* get_root() {
		return root;
	}

	Node* get_head() {
		return head;
	}

	void create() {
		int data;
		cout << "Enter the data: ";
		cin >> data;
		Node *newNode = new Node(data);

		if (root == NULL) {

			root = newNode;
			head = new Node();
			head->data = 0;
			head->left_child = root;
			head->right_child = head;
			root->left_child = head;
			root->right_child = head;
			root->l_bit = 0;
			root->r_bit = 0;
		} else {
			insertNode(root, newNode);
		}
	}

	void insertNode(Node *root, Node *newNode) {
		int choice;
		cout << "Do you want to insert it as a left child (1/0): ";
		cin >> choice;

		if (choice == 1) {
			if (root->l_bit == 0) {
				newNode->left_child = root->left_child;
				newNode->right_child = root;
				root->left_child = newNode;
				root->l_bit = 1;
			} else {
				insertNode(root->left_child, newNode);
			}
		} else {
			if (root->r_bit == 0) {
				newNode->right_child = root->right_child;
				newNode->left_child = root;
				root->r_bit = 1;
				root->right_child = newNode;
			} else {
				insertNode(root->right_child, newNode);
			}
		}
	}

	void print_inorder(Node *temp, Node *head) {
		while (temp != head) {

			while (temp->l_bit == 1) {
				temp = temp->left_child;
			}

			cout << " " << temp->data;

			while (temp->r_bit == 0) {
				temp = temp->right_child;
				if (temp == head) {
					return;
				}
				cout << " " << temp->data;
			}
			temp = temp->right_child;
		}
	}

	void print_preorder(Node *temp, Node *head) {

		while (temp != head) {

			cout << " " << temp->data;

			while (temp->l_bit == 1) {
				temp = temp->left_child;
				cout << " " << temp->data;

			}

			while (temp->r_bit == 0) {
				temp = temp->right_child;

				if (temp == head) {
					return;
				}
			}
			temp = temp->right_child;

		}

	}

	Node* search(Node *temp, Node *head, int data) {
		if (temp->data == data) {
			return temp;
		} else {
			while (temp != head) {

				while (temp->l_bit == 1) {
					temp = temp->left_child;
				}

				if (temp->data == data) {
					return temp;
				}

				while (temp->r_bit == 0) {
					temp = temp->right_child;
					if (temp == head) {
						return NULL;
					}
					if (temp->data == data) {
						return temp;
					}
				}
				temp = temp->right_child;
			}
		}
	}

	void deleteNode(Node *temp, Node *node_delete) {

		Node *parent, *temp_s;
		int flag = 0;

		if (temp->l_bit == 1 && temp->r_bit == 1) {
			parent = temp;
			temp_s = temp->right_child;
			while (temp_s->l_bit == 1) {
				flag = 1;
				parent = temp_s;
				temp_s = temp_s->left_child;
			}
			if (flag == 0) {
				temp->data = temp_s->data;
				parent->r_bit = 0;
				parent->l_bit = 0;
				parent->left_child = temp_s->left_child;
			}
			cout << "Node Deleted...\n";
			return;

		}

		if (temp->l_bit == 1 && temp->r_bit == 0) {
			if (parent->left_child == temp) {
				temp->left_child->right_child = parent;
				parent->left_child = temp->left_child;
			} else {
				temp->left_child->right_child = temp->right_child;
				parent->right_child = temp->left_child;
			}

			temp = NULL;
			delete temp;
			cout << "Node Deleted....";
			return;
		}

		if (temp->l_bit == 0 && temp->r_bit == 1) {
			if (parent->left_child == temp) {
				parent->left_child = temp->right_child;
				temp->right_child->left_child = temp->left_child;
				temp->right_child->right_child = parent;
			} else {
				parent->right_child = temp->right_child;
				temp->right_child->left_child = parent;
			}

			temp = NULL;
			delete temp;
			cout << "Node Deleted....";
			return;
		}

	}

};

int main() {
	TBT obj;
	Node *root;
	Node *head;
	int search;
	Node *found;

	int choice;

	while (choice != 6) {
		cout << "\n**********MAIN MENU***********\n";jjm
		cout
				<< "1. Insert a node\n2. Print inorder\n3. Print preorder\n4. Search a node\n5. Exit\n";

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			obj.create();
			break;

		case 2:
			root = obj.get_root();
			head = obj.get_head();
			if (root != NULL) {
				obj.print_inorder(root, head);
			} else {
				cout << "Tree not present add nodes first...\n";
			}
			break;

		case 3:
			root = obj.get_root();
			head = obj.get_head();
			if (root != NULL) {
				obj.print_preorder(root, head);
			} else {
				cout << "Tree not present add nodes first...\n";
			}
			break;

		case 4:
			cout << "Enter the data you want to search: ";
			cin >> search;

			root = obj.get_root();
			head = obj.get_head();

			found = obj.search(root, head, search);
			if (found != NULL) {
				cout << "Node Present in the tree\n";
			} else {
				cout << "Node Not found\n";
			}

			break;



		case 5:
			cout << "Exiting\nThank you!!!!!!!!!!!\n";
			break;

		default:
			cout << "Enter a valid choice....\n";
			break;
		}
	}

	return 0;
}

