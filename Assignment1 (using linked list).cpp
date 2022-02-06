//Author:- Nikita Gokhale
/*Beginning with an empty binary BT, Construct binary BT by inserting the values in the order given.
After constructing a binary BT perform following operations on it-
1.Perform in-order/preorder and post order traversal <-
2.Change a BT so that the roles of the left and right pointers are swapped at every node
3.Find the height of BT <-
4.Copy this BT to another [operator=]
5.Count number of leaves, number of internal nodes. <-
6.Erase all nodes in a binary BT.
->(implement both recursive and non-recursive methods)
*/
#include<iostream>

using namespace std;

//Node class for BT recursive functions
class Node
{

public:
    char data;
    Node *left;
    Node *right;

    Node(char data = '\0')
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    friend class BT;
    friend class Stack;
};

class BT
{
public:
    Node *root;
    Node *traverse;

    BT()
    {
        root = nullptr;
        traverse = nullptr;
    }

    void createBT()
    {
        char data;
        Node *temp = new Node();
        cout<<"Enter the data for root node:- ";
        cin>>temp->data;
        root = traverse = temp;
        createSubTree(traverse);
    }

    void createSubTree(Node *traverse)
    {
        char data;
        int flag;
        cout<<"Create left sub tree for node "<<traverse->data<<"? Enter 0/1:- ";
        cin>>flag;
        if(flag)
        {
            Node *temp = new Node();
            traverse->left = temp;
            cout<<"Enter data:- ";
            cin>>temp->data;
            createSubTree(traverse->left);
        }
        cout<<"Create right sub tree for node "<<traverse->data<<"? Enter 0/1:- ";
        cin>>flag;
        if(flag)
        {
            Node *temp = new Node();
            traverse->right = temp;
            cout<<"Enter data:- ";
            cin>>temp->data;
            createSubTree(traverse->right);
        }
    }

    void preorder(Node *traverse)
    {
        if(traverse!=nullptr)
        {
            cout<<traverse->data<<"  ";
            preorder(traverse->left);
            preorder(traverse->right);
        }
        else if(traverse == root)
            cout<<"Tree is empty!";
    }

    void inorder(Node *traverse)
    {
        if(traverse!=nullptr)
        {
            inorder(traverse->left);
            cout<<traverse->data<<"  ";
            inorder(traverse->right);
        }
        else if(traverse == root)
            cout<<"Tree is empty!";
    }

    void postorder(Node *traverse)
    {
        if(traverse!=nullptr)
        {
            postorder(traverse->left);
            postorder(traverse->right);
            cout<<traverse->data<<"  ";
        }
        else if(traverse == root)
            cout<<"Tree is empty!";
    }

    void swapRightLeft(Node *traverse)
    {
        if(traverse->left!=nullptr || traverse->right!=nullptr)
        {
            Node *temp;
            temp = traverse->left;
            traverse->left = traverse->right;
            traverse->right = temp;
        }
        if(traverse->left!=nullptr)
            swapRightLeft(traverse->left);
        if(traverse->right!=nullptr)
            swapRightLeft(traverse->right);
    }

    int height(Node *traverse)
    {
        int hl, hr;
        if(traverse==NULL)
            return 0;
        if(traverse->left==NULL && traverse->right==NULL)
            return 0;
        hl = height(traverse->left);
        hr = height(traverse->right);
        if(hl>hr)
            return hl+1;
        else
            return hr+1;
    }

    Node *copy_BT(Node *traverse)
    {
        Node *traverse2 = nullptr;
        if(traverse != nullptr)
        {
            traverse2 = new Node();
            traverse2->data = traverse->data;
            traverse2->left = copy_BT(traverse->left);
            traverse2->right = copy_BT(traverse->right);
        }
        return traverse2;
    }

    int count_leaves(Node *traverse)
    {
        int i;
        if(traverse==NULL)
            return 0;
        if(traverse->left==NULL && traverse->right==NULL)
            return 1;

        i = count_leaves(traverse->left) + count_leaves(traverse->right);

        return i;
    }

    int count_nodes(Node *traverse)
    {
        int i;
        if(traverse == nullptr)
            return 0;
        i = 1 + count_nodes(traverse->left) + count_nodes(traverse->right);
        return i;
    }

    void delete_BT(Node *traverse)
    {
        if(traverse!=nullptr)
        {
            delete_BT(traverse->left);
            delete_BT(traverse->right);
            delete traverse;
        }
    }
};

//For NR traversal functions
struct stacknode
{
    Node *data;
    int flag;
};

class Stack_Node
{
    union
    {
        Node *data;
        stacknode data_stacknode;
    };
    Stack_Node *next;

public:
    Stack_Node()
    {
        this->data = data;
        this->data_stacknode = data_stacknode;
        next = nullptr;
    }

    friend class Stack;
};

class Stack
{
public:
    Stack_Node *top;

    Stack(){top=nullptr;}

    int empty()
    {
        if(top==nullptr)
            return 1;
        return 0;
    }

    void push(Node *p)
    {
        Stack_Node *temp = new Stack_Node();
        temp->next = top;
        top = temp;
        temp->data = p;
    }

    void push(stacknode t)
    {
        Stack_Node *temp = new Stack_Node();
        temp->next = top;
        top = temp;
        temp->data_stacknode = t;
    }

    Node *pop()
    {
        Node *temp = top->data;
        top = top->next;
        return temp;
    }

    stacknode pop_sn()
    {
        stacknode temp = top->data_stacknode;
        top = top->next;
        return temp;
    }
};

void preorder_NR(Node *T)
{
    Stack s;
    if(T == nullptr)
        cout<<"Tree is empty!";
    while(T!=nullptr)
    {
        cout<<T->data<<"  ";
        s.push(T);
        T = T->left;
    }
    while(!s.empty())
    {
        T = s.pop();
        T = T->right;
        while(T != nullptr)
        {
            cout<<T->data<<"  ";
            s.push(T);
            T = T->left;
        }
    }
}

void inorder_NR(Node *T)
{
    Stack s;
    if(T == nullptr)
        cout<<"Tree is empty!";
    while(T!=nullptr)
    {
        s.push(T);
        T = T->left;
    }
    while(!s.empty())
    {
        T = s.pop();
        cout<<T->data<<"  ";
        T = T->right;
        while(T != nullptr)
        {
            s.push(T);
            T = T->left;
        }
    }
}

void postorder_NR(Node *T)
{
    Stack s;
    stacknode stnode;
    Node *p;
    if(T == nullptr)
        cout<<"Tree is empty!";
    while(T!=nullptr)
    {
        stnode.data = T;
        stnode.flag = 0;
        s.push(stnode);
        T = T->left;
    }
    while(!s.empty())
    {
        stnode = s.pop_sn();
        if(!stnode.flag)
        {
            stnode.flag = 1;
            s.push(stnode);
            T = stnode.data;
            T = T->right;
            while(T != nullptr)
            {
                stnode.data = T;
                stnode.flag = 0;
                s.push(stnode);
                T = T->left;
            }
        }
        else
        {
            p = stnode.data;
            cout<<p->data<<"  ";
        }
    }
}

int main()
{
    /*      A
       B          C
         D      G    H
       E   F

    */
    BT obj, obj_copy;
    int choice, ht, no_leaves, no_nodes;
    while(choice != 9)
    {
        cout<<"\n*************START*************";
        cout<<"\nMAIN MENU\n1. Create binary tree.\n2. Traversals.\n";
        cout<<"3. Swap right left pointers.\n4. Height.\n5. Make a copy of the tree.\n6. Print the copy.\n";
        cout<<"7. Count no of leaves and nodes.\n8. Delete the BT.\n9. Exit.\n";
        cout<<"Enter your choice:- ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 1:
            obj.createBT();
            break;

        case 2:
            cout<<"Preorder traversal:-"<<endl;
            cout<<"Recursive:- "<<endl;
            obj.preorder(obj.root);
            cout<<endl;
            cout<<"Non Recursive:- "<<endl;
            preorder_NR(obj.root);
            cout<<"\n\nInorder traversal:-"<<endl;
            cout<<"Recursive:- "<<endl;
            obj.inorder(obj.root);
            cout<<endl;
            cout<<"Non Recursive:- "<<endl;
            inorder_NR(obj.root);
            cout<<"\n\nPostorder traversal:-"<<endl;
            cout<<"Recursive:- "<<endl;
            obj.postorder(obj.root);
            cout<<endl;
            cout<<"Non Recursive:- "<<endl;
            postorder_NR(obj.root);
            break;

        case 3:
            obj.swapRightLeft(obj.root);
            cout<<"After swapping right and left roots:- \n";
            obj.preorder(obj.root);
            break;

        case 4:
            ht = obj.height(obj.root);
            cout<<"Height of tree = "<<ht;
            break;

        case 5:
            obj_copy.root = obj.copy_BT(obj.root);
            cout<<"The object in which the tree was copied:- \n";
            obj_copy.preorder(obj_copy.root);
            break;

        case 6:
            obj_copy.preorder(obj_copy.root);
            break;

        case 7:
            no_leaves = obj.count_leaves(obj.root);
            cout<<"No of leaves = "<<no_leaves;
            no_nodes = obj.count_nodes(obj.root);
            cout<<"\nNo of nodes = "<<no_nodes;
            break;

        case 8:
            obj.delete_BT(obj.root);
            obj.root = nullptr;
            cout<<"Successfully deleted BT.";
            break;

        case 9:
            cout<<"Thank you!";
            break;

        default:
            cout<<"Please enter a valid choice!";
            break;
        }
        cout<<"\n**************END**************\n\n";
    }

    return 0;
}
