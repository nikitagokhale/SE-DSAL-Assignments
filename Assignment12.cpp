#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Record
{
    int roll_no, division;
    string name, city;

public:
    Records(int roll_no=0, int division=0, string name="\0", string city="\0")
    {
        this->roll_no=roll_no;
        this->division=division;
        this->name=name;
        this->city=city;
    }

    friend class File;
};

class File
{
    Record record_entry;

public:
    File(){};

    void insert_entry()
    {
        ofstream fout("Records.txt", ios::app);
        if(fout.is_open())
        {
            cout<<"Enter your data"<<endl;
            cout<<"Roll number:- ";
            cin>>record_entry.roll_no;
            cout<<"Division:- ";
            cin>>record_entry.division;
            cin.ignore();
            cout<<"Name:- ";
            getline(cin, record_entry.name);
            cout<<"City:- ";
            getline(cin, record_entry.city);

            fout<<record_entry.roll_no;
            fout<<" ";
            fout<<record_entry.division;
            fout<<" ";
            fout<<record_entry.name;
            fout<<" ";
            fout<<record_entry.city;
            fout<<"\n";
            fout.close();
        }
        else
            cout<<"Error!";
    }

    void read_entry()
    {
        string str, str1, str2;
        ifstream fin("Records.txt");
        cin.ignore
        cout<<"Enter the roll number you want to search:- ";
        getline(cin, str)
        while(fin.eof()==0)
        {
            getline(fin, str1);
            if(str1.compare(str)==0)

        }
    }

    void display_records()
    {
        string str;
        ifstream fin("Records.txt");
        while(fin.eof() ==0)
        {
            getline(fin, str);
            cout<<str<<endl;
        }
        fin.close();
    }
};

int main()
{
    File obj;
    int choice;
    while(choice!=5)
    {
        cout << "\n***********START*********";
        cout << "\nMAIN MENU\n1. Insert a record.\n2. Read a record.\n3. Display all records.\n4. Delete record.\n5. Exit.\n";
        cout << "Enter your choice:- ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            obj.insert_entry();
            break;

        case 2:
            obj.read_entry();
            break;

        case 3:
            obj.display_records();
            break;

        case 4:
            break;

        case 5:
            cout<<"Thank you!";
            break;

        default:
            cout<<"Please enter a valid choice!";
            break;
        }
        cout<<"\n***********END***********\n\n";
    }
    return 0;
}
