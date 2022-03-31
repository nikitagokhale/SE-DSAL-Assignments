#include<iostream>
#define SIZE 10
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data = NULL)
    {
        this->data = data;
        next = nullptr;
    }
    friend class HashTable;
};

class HashTable
{
    Node hashtable[SIZE];
    Node *traverse;

public:
    HashTable()
    {
        traverse = nullptr;
    }

    int get_key(int data)
    {
        return (data%SIZE);
    }

    void insert_entry()
    {
        int data, key;
        cout<<"Enter the data:- ";
        cin>>data;
        key = get_key(data);
        traverse = &hashtable[key];
        if(hashtable[key].data != NULL)
        {
            while(traverse->next != nullptr)
                traverse = traverse->next;
            traverse->next = new Node();
            traverse = traverse->next;
        }
        traverse->data = data;
    }

    void search_entry()
    {
        int data, key, comparisons = 1;
        cout<<"Enter the data you want to search:- ";
        cin>>data;
        key = get_key(data);
        traverse = &hashtable[key];
        if(traverse->data != data && traverse->next != nullptr)
        {
            traverse = traverse->next;
            comparisons++;
            while(traverse->data != data && traverse != nullptr)
            {
                comparisons++;
                traverse = traverse->next;
            }
        }

        if(traverse->data == data)
            cout<<"Data:- "<<traverse->data<<"\nComparisons:- "<<comparisons;
        else
            cout<<"Data not found!"<<"\nComparisons:- "<<comparisons;
    }

    void display_hashtable()
    {
        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<". Data:- "<<hashtable[i].data;
            traverse = hashtable[i].next;
            while(traverse!=nullptr)
            {
                cout<<"  ->  Data:- "<<traverse->data;
                traverse = traverse->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    HashTable obj;
    int choice;
    while(choice != 4)
    {
        cout << "\n****************************START****************************";
        cout << "\nMAIN MENU\n1. Insert hash entry.\n2. Search a hash entry.\n3. Display Hash Table\n4. Exit.\n";
        cout << "Enter your choice:- ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            obj.insert_entry();
            break;

        case 2:
            obj.search_entry();
            break;

        case 3:
            obj.display_hashtable();
            break;

        case 4:
            cout << "Thank you!";
            break;

        default:
            cout << "Please enter a valid choice!";
            break;
        }
        cout << "\n*****************************END*****************************\n\n";
    }
    return 0;
}
