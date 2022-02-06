#include<iostream>

using namespace std;

class Node
{
    char data;
    bool flag;
    Node *next;
    Node *down;

public:
    Node(char data = '\0', bool flag = false)
    {
        this->data = data;
        this->flag = flag;
        next = nullptr;
        down = nullptr;
    }

    friend class GLL;
};

class GLL
{
    Node *head;
    Node *tail;
    Node *traverse;

public:
    GLL()
    {
        head = nullptr;
        tail = nullptr;
        traverse = nullptr;
    }

    void display()
    {
        traverse = head;
        cout<<"\n(";
        while(traverse!=nullptr)
        {
            if(!traverse->flag)
                cout<<traverse->data;
            else
                displayDownLink(traverse->down);
            traverse = traverse->next;
            if(traverse != nullptr)
                cout<<", ";
        }
        cout<<")\n";
    }

    void displayDownLink(Node *T)
    {
        cout<<"(";
        while(T!=nullptr)
        {
            if(!T->flag)
                cout<<T->data;
            else
                displayDownLink(T->down);
            T = T->next;
            if(T!=nullptr)
                cout<<", ";
        }
        cout<<")";
    }

    void createHeaderNode()
    {
        char data, t_f;
        bool flag;

        if(head==nullptr)
        {
            Node *temp = new Node(data, flag);
            head = temp;
            tail = temp;
            cout<<"\nHeader node created successfully";
            cout<<"\nDo you wish to enter data in the node? Enter t/f:- ";
            cin>>t_f;
            if(t_f == 't')
            {
                cout<<"Enter char data:- ";
                cin>>temp->data;
                temp->flag = false;
            }
            else
                temp->flag = true;
        }
        else
            cout<<"\nHeader node already exists!\n";
    }

    void createFrontNode()
    {
        char data, t_f;
        bool flag;

        if(head != nullptr)
        {
            Node *temp = new Node(data,flag);
            tail->next = temp;
            tail = temp;
            cout<<"\nFront node created successfully";
            cout<<"\nDo you wish to enter data in node? Enter t/f:- ";
            cin>>t_f;
            if(t_f == 't')
            {
                cout<<"Enter char data:- ";
                cin>>temp->data;
                temp->flag = false;
            }
            else
                temp->flag = true;
        }
        else
            cout<<"\nCreate a header node first!\n";
    }

    void createDownLink()
    {
        int loc, count=0;
        char data, t_f;
        bool flag;

        cout<<"\nEnter the location for down link:- ";
        cin>>loc;
        loc -=1;
        traverse = head;
        while(traverse!=nullptr)
        {
            count++;
            traverse = traverse->next;
        }

        if(loc<count)
        {
            traverse = head;
            for(int i=0;i<loc;i++)
            {
                if(loc == 0)
                    break;
                traverse = traverse->next;
            }
        }

        if(loc>count-1)
            cout<<"There is/are "<<count<<" node/s in the list!";
        else if(!traverse->flag)
            cout<<"This node has data!";
        else if(traverse->down != nullptr)
            cout<<"Down link already exists!";
        else
            downlink(traverse);
        cout<<endl;
    }

    void downlink(Node *header)
    {
        int noe, count = 0, data;
        char t_f;
        bool flag;
        Node *end;
        cout<<"Enter the no of nodes you want to create for the downlink:- ";
        cin>>noe;
        for(int i=0;i<noe;i++)
        {
            Node *temp = new Node(data, flag);
            if(i == 0)
                header->down = temp;
            else
                end->next = temp;
            end = temp;
            cout<<"\nDo you wish to enter data in node "<<i+1<<"? Enter t/f:- ";
            cin>>t_f;
            if(t_f == 't')
            {
                cout<<"Enter char data:- ";
                cin>>temp->data;
                temp->flag = false;
            }
            else
            {
                temp->flag = true;
                downlink(temp);
            }
        }
    }
};

int main()
{
    GLL obj;
    int choice = 0;
    //((A, B), C, ((D, E), F))

    while(choice!=5)
    {
        cout<<"\nMAIN MENU\n1. Create header node.\n2. Create front node.\n3. Create down link.\n4. Display GLL.\n5. Exit.";
        cout<<"\nEnter your choice:- ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            obj.createHeaderNode();
            break;

        case 2:
            obj.createFrontNode();
            break;

        case 3:
            obj.createDownLink();
            break;

        case 4:
            obj.display();
            break;

        case 5:
            cout<<"Thank you!";
            break;

        default:
            cout<<"Enter a valid choice!";
        }
    }

    return 0;
}
