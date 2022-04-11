//============================================================================
// Name        : Assignment5.cpp
// Author      : Nikita Gokhale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
#include<string.h>
#define SIZE 26
using namespace std;

class Node
{
    string keyword;
    string meaning;
    Node *next;

public:
    Node(string keyword = "\0", string meaning="\0")
    {
        this->keyword = keyword;
        this->meaning = meaning;
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

    int get_key(string &ref_keyword)
    {
    	char letter;
    	int ASCII;
        letter = ref_keyword[0];
        ASCII = int(letter);
        if(ASCII<97)
        	ASCII += 33;
        ASCII -= 97;
        return ASCII%26;
    }

    void insert_entry(string &ref_keyword, string &ref_meaning)
    {
    	int key;
        key = get_key(ref_keyword);
        traverse = &hashtable[key];
        if(hashtable[key].keyword != "\0")
        {
            while(traverse->next != nullptr)
                traverse = traverse->next;
            traverse->next = new Node();
            traverse = traverse->next;
        }
        traverse->keyword = ref_keyword;
        traverse->meaning = ref_meaning;
    }

    void search_entry()
    {
    	string keyword, meaning;
        int key, comparisons = 1;
        cin.ignore();
        cout<<"Enter the keyword you want to search:- ";
        getline(cin, keyword);
        key = get_key(keyword);
        traverse = &hashtable[key];
        if(keyword.compare(traverse->keyword) != 0 && traverse->next != nullptr)
        {
            traverse = traverse->next;
            comparisons++;
            while(keyword.compare(traverse->keyword) != 0 && traverse != nullptr)
            {
                comparisons++;
                traverse = traverse->next;
            }
        }

        if(keyword.compare(traverse->keyword) == 0)
            cout<<"Keyword:- "<<traverse->keyword<<"  Meaning:- "<<traverse->meaning<<"\nComparisons:- "<<comparisons;
        else
            cout<<"Data not found!"<<"\nComparisons:- "<<comparisons;
    }

    void display_hashtable()
    {
        for(int i=0;i<SIZE;i++)
        {
            char letter = char(i+97);
            cout<<letter<<". Keyword:- "<<hashtable[i].keyword<<"  Meaning:- "<<hashtable[i].meaning;
            traverse = hashtable[i].next;
            while(traverse!=nullptr)
            {
                cout<<"  \n-> Keyword:- "<<traverse->keyword<<"  Meaning:- "<<traverse->meaning;
                traverse = traverse->next;
            }
            cout<<endl;
        }
    }

    void delete_entry()
    {
    	string keyword, meaning;
    	int key, flag=0;
    	Node *temp1;
    	cin.ignore();
    	cout<<"Enter the keyword you want to delete:- ";
    	getline(cin, keyword);
    	key = get_key(keyword);
    	traverse = &hashtable[key];
    	if(keyword.compare(traverse->keyword) != 0 && traverse->next != nullptr)
    	{
    	    traverse = traverse->next;
    	    while(keyword.compare(traverse->keyword) != 0 && traverse != nullptr)
    	    {
    	    	temp1 = traverse;
    	        traverse = traverse->next;
    	    }
    	    flag = 1;
    	}
    }
};

int main()
{
    HashTable obj;
    string keyword, meaning;
    int choice;
    while(choice != 4)
    {
        cout << "\n****************************START****************************";
        cout << "\nMAIN MENU\n1. Insert hash entry.\n2. Search a hash entry.\n3. Display Hash Table.\n4. Delete hash entry.\n5. Exit.\n";
        cout << "Enter your choice:- ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cin.ignore();
            cout<<"Enter the keyword:- ";
            getline(cin, keyword);
            cout<<"Enter the meaning:- ";
            getline(cin, meaning);
            obj.insert_entry(keyword, meaning);
            break;

        case 2:
            obj.search_entry();
            break;

        case 3:
            obj.display_hashtable();
            break;

        case 4:
        	obj.delete_entry();
        	break;

        case 5:
        	cout<<"Thank you!";
        	break;

        default:
            cout << "Please enter a valid choice!";
            break;
        }
        cout << "\n*****************************END*****************************\n\n";
    }
    return 0;
}
