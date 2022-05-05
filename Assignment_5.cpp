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
    int flag, comparisons;

    HashTable(int flag = 0, int comparisons = 0)
    {
    	this->flag = flag;
    	this->comparisons = comparisons;
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
    	flag = 0;
    	search_entry(ref_keyword);
        if(!flag)
        {
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
        else
        	cout<<"Keyword is repeated!";
    }

    void search_entry(string &ref_keyword)
    {
    	string meaning;
        int key;
        flag = 0;
        comparisons = 1;
        key = get_key(ref_keyword);
        traverse = &hashtable[key];
        if(ref_keyword.compare(traverse->keyword) != 0 && traverse->next != nullptr)
        {
            traverse = traverse->next;
            comparisons++;
            while(traverse != nullptr && ref_keyword.compare(traverse->keyword) != 0)
            {
                comparisons++;
                traverse = traverse->next;
            }
        }
        if(traverse != nullptr && ref_keyword.compare(traverse->keyword) == 0)
        {
        	flag = 1;
            cout<<"Keyword:- "<<traverse->keyword<<"  Meaning:- "<<traverse->meaning<<endl;
        }
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
    	int key;
    	cin.ignore();
    	cout<<"Enter the keyword you want to delete:- ";
    	getline(cin, keyword);
    	key = get_key(keyword);
    	traverse = &hashtable[key];
    	if(traverse->next != nullptr && keyword.compare(traverse->keyword) != 0)
    	{
    		Node *temp = traverse;
    	    traverse = traverse->next;
    	    while(traverse != nullptr && keyword.compare(traverse->keyword) != 0)
    	    {
    	    	temp = traverse;
    	        traverse = traverse->next;
    	    }
            if(traverse!= nullptr)
            {
            	temp->next = traverse->next;
            	delete traverse;
            	cout<<"Keyword deleted successfully!";
            }
            else
                cout<<"Keyword not found!";
    	}
    	else if(keyword.compare(traverse->keyword)==0)
        {
            if(traverse->next == nullptr)
                traverse->keyword = traverse->meaning = "\0";
            else
            {
                Node *temp = traverse->next;
                traverse->keyword = traverse->next->keyword;
                traverse->meaning = traverse->next->meaning;
                traverse->next = traverse->next->next;
                delete temp;
            }
        	cout<<"Keyword deleted successfully!";
        }
        else
            cout<<"Keyword not found!";
    }
};

int main()
{
    HashTable obj;
    string keyword, meaning;
    int choice;
    while(choice != 5)
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
        	cin.ignore();
        	cout<<"Enter the keyword you want to search:- ";
        	getline(cin, keyword);
            obj.search_entry(keyword);
            if(!obj.flag)
            	cout<<"Data not found!\n";
            cout<<"Comparisons:- "<<obj.comparisons;
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
