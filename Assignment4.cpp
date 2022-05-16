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

	void insert_entry_with_replacement()
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
        cout<<endl;
	}

	void display_hashtable()
	{
	    for(int i=0;i<SIZE;i++)
            cout<<i<<". Name:- "<<hashtable[i].name<<", Telephone number:- "<<hashtable[i].tele_num<<endl;
	}
};

int main()
{
	HashTable telephone_diary_without_replacement, telephone_diary_with_replacement;
	int choice;
	cout << "\n****************************START****************************";
	while (choice != 3)
	{
        cout << "\nMAIN MENU\n1. Telephone diary without replacement.\n2. Telephone diary with replacement.\n3. Exit.\n";
		cout << "Enter your choice:- ";
		cin >> choice;
		switch(choice)
		{
        case 1:
            cout << "\n*************WITHOUT REPLACEMENT*************";
            int choice_without_replacement;
            while(choice_without_replacement != 4)
            {
                cout << "\nMAIN MENU\n1. Insert Hash Entry.\n2. Search a hash entry.\n3. Display Hash Table\n4. Exit.\n";
                cout << "Enter your choice:- ";
                cin >> choice_without_replacement;
                cout << endl;
                switch (choice_without_replacement)
                {
                case 1:
                    telephone_diary_without_replacement.insert_entry();
                    break;

                case 2:
                    telephone_diary_without_replacement.search_entry();
                    break;

                case 3:
                    telephone_diary_without_replacement.display_hashtable();
                    break;

                case 4:
                    cout << "Thank you!";
                    break;

                default:
                    cout << "Please enter a valid choice!";
                    break;
                }
            }
            cout << "\n**************END WITHOUT REPLACEMENT**************\n\n";
            break;

        case 2:
            cout << "\n*************WITH REPLACEMENT*************";
            int choice_with_replacement;
            while(choice_with_replacement != 4)
            {
                cout << "\nMAIN MENU\n1. Insert Hash Entry.\n2. Search a hash entry.\n3. Display Hash Table\n4. Exit.\n";
                cout << "Enter your choice:- ";
                cin >> choice_with_replacement;
                cout << endl;
                switch (choice_with_replacement)
                {
                case 1:
                    telephone_diary_with_replacement.insert_entry_with_replacement();
                    break;

                case 2:
                    telephone_diary_with_replacement.search_entry();
                    break;

                case 3:
                    telephone_diary_with_replacement.display_hashtable();
                    break;

                case 4:
                    cout << "Thank you!";
                    break;

                default:
                    cout << "Please enter a valid choice!";
                    break;
                }
            }
            cout << "\n**************WITH REPLACEMENT**************\n\n";
            break;

        case 3:
			cout << "Thank you!";
			break;

		default:
			cout << "Please enter a valid choice!";
			break;
		}
		cout<<"\n\n";
	}
    cout << "\n*****************************END*****************************\n\n";
	return 0;
}
