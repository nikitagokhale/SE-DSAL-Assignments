//Author:- Nikita Gokhale
//A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords,
//updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many
//maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation.
#include<iostream>
#include<string.h>

using namespace std;

class Node
{
    string keyword;
    string meaning;
    Node *left;
    Node *right;

public:
    Node(string keyword = "\0", string meaning = "\0")
    {
        this->keyword = keyword;
        this->meaning = meaning;
        left = nullptr;
        right = nullptr;
    }

    friend class BST;
};

class BST
{
public:
    Node *root;
    int flag, count;

    BST()
    {
        root = nullptr;
    }

    Node *insert(Node *traverse, string &ref_keyword, string &ref_meaning)
    {
        string keyword;
        string meaning;
        if(traverse == nullptr)
        {
            traverse = new Node();
            traverse->keyword = ref_keyword;
            traverse->meaning = ref_meaning;
            return traverse;
        }
        if(ref_keyword.compare(traverse->keyword) > 0)
        {
            traverse->right = insert(traverse->right, ref_keyword, ref_meaning);
            return traverse;
        }

        traverse->left = insert(traverse->left, ref_keyword, ref_meaning);
        return traverse;
    }

    Node *delete_node(Node *traverse, string &ref_keyword)
    {
        string keyword;
        string meaning;

        if(root == nullptr)
        {
            cout<<"Tree is empty!";
            flag = 0;
            return nullptr;
        }
        if(traverse == nullptr)
        {
            cout<<"Element not found!";
            flag = 0;
            return nullptr;
        }
        if(ref_keyword.compare(traverse->keyword) < 0)
        {
            traverse->left = delete_node(traverse->left, ref_keyword);
            return traverse;
        }
        if(ref_keyword.compare(traverse->keyword) > 0)
        {
            traverse->right = delete_node(traverse->right, ref_keyword);
            return traverse;
        }

        if(traverse->left==nullptr && traverse->right==nullptr)
        {
            delete traverse;
            return nullptr;
        }
        if(traverse->left==nullptr)
        {
            Node *temp = traverse;
            traverse = traverse->right;
            delete temp;
            return traverse;
        }
        if(traverse->right==nullptr)
        {
            Node *temp = traverse;
            traverse = traverse->left;
            delete temp;
            return traverse;
        }
        Node *temp = find_min(traverse->right);
        traverse->keyword = temp->keyword;
        traverse->meaning = temp->meaning;
        traverse->right = delete_node(traverse->right, temp->keyword);
        return traverse;
    }

    Node *find_min(Node *traverse)
    {
        while(traverse->left != nullptr)
            traverse = traverse->left;
        return traverse;
    }

    Node *update(Node *traverse, string &ref_keyword)
    {
        string ref_meaning;
        traverse = delete_node(traverse, ref_keyword);
        if(flag)
        {
            cout<<"Enter new keyword:-";
            getline(cin, ref_keyword);
            cout<<"Enter new meaning:-";
            getline(cin, ref_meaning);
            traverse = insert(traverse, ref_keyword, ref_meaning);
        }
        return traverse;
    }

    void asc_order(Node *traverse)
    {
        if(traverse!=nullptr)
        {
            asc_order(traverse->left);
            cout<<traverse->keyword<<":- "<<traverse->meaning<<endl;
            asc_order(traverse->right);
        }
        else if(traverse == root)
            cout<<"Tree is empty!";
    }

    void desc_order(Node *traverse)
    {
        if(traverse!=nullptr)
        {
            desc_order(traverse->right);
            cout<<traverse->keyword<<":- "<<traverse->meaning<<endl;
            desc_order(traverse->left);
        }
        else if(traverse == root)
            cout<<"Tree is empty!";
    }

    Node *find_keyword(Node *traverse, string &ref_keyword)
    {
        string keyword;
        string meaning;

        if(root == nullptr)
        {
            cout<<"Tree is empty!";
            flag = 0;
            return nullptr;
        }
        if(traverse == nullptr)
        {
            cout<<"Element not found!";
            flag = 0;
            return root;
        }
        if(ref_keyword.compare(traverse->keyword)==0)
        {
            count++;
            cout<<traverse->keyword<<":- "<<traverse->meaning<<endl;
            return traverse;
        }
        else
            count++;

        if(ref_keyword.compare(traverse->keyword)>0)
            return(find_keyword(traverse->right, ref_keyword));

        return(find_keyword(traverse->left, ref_keyword));
    }
};

int main()
{
    BST dictionary;
    int choice;
    Node *find;
    string keyword;
    string meaning;
    while(choice != 7)
    {
        cout<<"\n*************START*************";
        cout<<"\nMAIN MENU\n1. Add keyword.\n2. Delete keyword.\n";
        cout<<"3. Update keyword.\n4. Display in ascending order.\n5. Display in descending order.\n6. Find keyword.\n";
        cout<<"7. Exit.\n";
        cout<<"Enter your choice:- ";
        cin>>choice;
        cout<<endl;
        cin.ignore();
        switch(choice)
        {
        case 1:
            cout<<"Enter the keyword:- ";
            getline(cin, keyword);
            cout<<"Enter the meaning:- ";
            getline(cin, meaning);
            dictionary.root = dictionary.insert(dictionary.root, keyword, meaning);
            break;

        case 2:
            dictionary.flag = 1;
            cout<<"Enter the keyword you want to delete:- ";
            getline(cin, keyword);
            dictionary.root = dictionary.delete_node(dictionary.root, keyword);
            if(dictionary.flag)
                cout<<"Keyword successfully deleted.";
            break;

        case 3:
            dictionary.flag = 1;
            cout<<"Enter the keyword you want to update:- ";
            getline(cin, keyword);
            dictionary.root = dictionary.update(dictionary.root, keyword);
            if(dictionary.flag)
                cout<<"Keyword successfully updated.";
            break;

        case 4:
            dictionary.asc_order(dictionary.root);
            break;

        case 5:
            dictionary.desc_order(dictionary.root);
            break;

        case 6:
            dictionary.flag = 1;
            dictionary.count = 0;
            cout<<"Enter the keyword you want to find:- ";
            getline(cin, keyword);
            find = dictionary.find_keyword(dictionary.root, keyword);
            if(dictionary.flag)
                cout<<"No. of comparisons = "<<dictionary.count;
            break;

        case 7:
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
