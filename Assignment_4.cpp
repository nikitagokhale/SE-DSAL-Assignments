//============================================================================
// Name        : Assignment4.cpp
// Author      : Nikita Gokhale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

class HashEntry
{
	long int tele_num;
	string name;

public:
	HashEntry(long int tele_num = 0, string name = "\0")
	{
		this->tele_num = tele_num;
		this->name = name;
	}
	friend class HashTable;
};

class HashTable
{
	HashEntry hashtable[SIZE], hashentry;

public:
	long int get_key(long int &ref_telephone_num)
	{
		return ref_telephone_num%SIZE;
	}

	bool is_full()
	{
	    for(int i=0;i<SIZE;i++)
        {
            if(hashtable[i].tele_num == 0)
                return false;
        }
        return true;
	}

	void swap_(HashEntry &ref_hashtable_entry, HashEntry &ref_hashentry)
	{
	    HashEntry temp;
	    temp = ref_hashentry;
	    ref_hashentry = ref_hashtable_entry;
	    ref_hashtable_entry = temp;
	}

	void insert_entry()
	{
		long int telephone_num, key;
		string name;
		if(!is_full())
        {
            cin.ignore();
            cout << "Enter the name of the person:- ";
            getline(cin, name);
            cout << "Enter the telephone number:- ";
            cin >> telephone_num;
            cin.ignore();

            key = get_key(telephone_num);

            while (hashtable[key].tele_num != 0)
                key = (key + 1) % SIZE;

            hashtable[key].tele_num = telephone_num;
            hashtable[key].name = name;
        }
        else
            cout<<"The hash table is full!";
	}

	void insert_entry_wr()
	{
		long int key, key_existing_entry;
		if(!is_full())
        {
            cin.ignore();
            cout << "Enter the name of the person:- ";
            getline(cin, hashentry.name);
            cout << "Enter the telephone number:- ";
            cin >> hashentry.tele_num;
            cin.ignore();

            key = get_key(hashentry.tele_num);
            if(hashtable[key].tele_num!=0)
            {
                key_existing_entry = get_key(hashtable[key].tele_num);
                if(key != key_existing_entry)
                    swap_(hashtable[key], hashentry);
                key = (key+1)%SIZE;
                while(hashtable[key].tele_num!=0)
                    key = (key+1)%SIZE;
            }
            hashtable[key] = hashentry;
        }
        else
            cout<<"The hash table is full!";
	}

	void search_entry()
	{
	    int count = 0, comparison = 1;
		long int telephone_num, key;
		cout<<"Enter the telephone number you want to search:- ";
		cin>>telephone_num;
		key = get_key(telephone_num);
		while(hashtable[key].tele_num != telephone_num && count<SIZE)
        {
            key = (key+1) % SIZE;
            count++;
            comparison++;
        }
        if(count<SIZE)
            cout<<"Name:- "<<hashtable[key].name<<", Telephone number:- "<<hashtable[key].tele_num<<"\nNo. of comparisons ="<<comparison;
        else
            cout<<"Number not found!"<<"\nNo. of comparisons ="<<comparison;
	}

	void display_ht()
	{
	    for(int i=0;i<SIZE;i++)
            cout<<i<<". Name:- "<<hashtable[i].name<<", Telephone number:- "<<hashtable[i].tele_num<<endl;
	}
};

int main()
{
	HashTable Telephone_Diary;
	int choice;
	while (choice != 7)
	{
		cout << "\n*************START*************";
		cout << "\nMAIN MENU\n1. Insert Hash Entry.\n2. Insert Hash Entry with replacement.\n3. Search a hash entry.\n4. Display Hash Table\n7. Exit.\n";
		cout << "Enter your choice:- ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			Telephone_Diary.insert_entry();
			break;

		case 2:
		    Telephone_Diary.insert_entry_wr();
		    break;

		case 3:
			Telephone_Diary.search_entry();
			break;

		case 4:
			Telephone_Diary.display_ht();
			break;

		case 7:
			cout << "Thank you!";
			break;

		default:
			cout << "Please enter a valid choice!";
			break;
		}
		cout << "\n**************END**************\n\n";
	}

	return 0;
}
