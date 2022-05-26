//Represent a given graph using adjacency list to perform DFS and BFS. Use the map
//of the area around the college as the graph. Identify the prominent landmarks as
//nodes and perform DFS and BFS on that.
#include<iostream>
#define SIZE 30
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }

    friend class Graph;
};

class SLL_Node
{
    int data;
    SLL_Node *next;

public:
    SLL_Node(int data=0)
    {
        this->data = data;
        next = nullptr;
    }

    friend class SLL;
};

class SLL
{
    SLL_Node *head;
    SLL_Node *traverse;

public:
    SLL()
    {
        head = nullptr;
        traverse = nullptr;
    }

    void insert_node(int &ref_data)
    {
        if(head == nullptr)
            head = new SLL_Node(ref_data);
        else
        {
            traverse = head;
            while(traverse->next!=nullptr)
                traverse = traverse->next;
            traverse->next = new SLL_Node(ref_data);
        }
    }

    bool find_data(int &ref_data)
    {
        traverse = head;
        while(traverse!=nullptr)
        {
            if(traverse->data == ref_data)
                return true;
            traverse = traverse->next;
        }
        return false;
    }

    void delete_SLL()
    {
        traverse = head;
        while(traverse!=nullptr)
        {
            SLL_Node *temp = traverse;
            traverse = traverse->next;
            delete temp;
        }
        head = nullptr;
    }

    int obj_size()
    {
        int cnt;
        traverse = head;
        while(traverse!=nullptr)
            cnt++;
        return cnt;
    }

    friend class Graph;
};

class Graph
{
    Node arr[SIZE];
    Node *traverse;
    int no_vertices, no_edges;

public:
    SLL obj, obj2;
    Graph(int no_vertices = 0, int no_edges = 0)
    {
        this->no_vertices = no_vertices;
        this->no_edges = no_edges;
        traverse = nullptr;
    }

    void create_graph()
    {
        int i, j;
        cout<<"Enter no. of vertices:- ";
        cin>>no_vertices;
        for(i=0;i<no_vertices;i++)
        {
            cout<<"\nEnter data for vertex no. "<<i+1<<":- ";
            cin>>arr[i].data;
            traverse = &arr[i];
            cout<<"Enter no. of edges for vertex "<<arr[i].data<<":- ";
            cin>>no_edges;
            for(j=0;j<no_edges;j++)
            {
                traverse->next = new Node();
                traverse = traverse->next;
                cout<<"Enter data for vertex at edge "<<j+1<<":- ";
                cin>>traverse->data;
            }
        }
    }

    void display()
    {
        int i, j;
        for(i=0;i<no_vertices;i++)
        {
            cout<<arr[i].data;
            traverse = &arr[i];
            while(traverse->next!=nullptr)
            {
                traverse = traverse->next;
                cout<<" ==> "<<traverse->data;
            }
            cout<<"\n|\n";
        }
    }

    void DFS_traversal(int &ref_data)
    {

        Node *traverse = &arr[0];
        int i = 0;
        while(traverse->data!=ref_data)
        {
            i++;
            traverse = &arr[i];
        }
        if(traverse->data == ref_data)
        {
            if(!obj.find_data(ref_data))
                cout<<traverse->data<<" ";
            obj.insert_node(traverse->data);
            while(traverse->next!=nullptr)
            {
                traverse = traverse->next;
                if(!obj.find_data(traverse->data))
                    DFS_traversal(traverse->data);
            }
        }
    }

    void BFS_traversal(int &ref_data)
    {
        Node *traverse = &arr[0];
        int i = 0;
        while(traverse->data!=ref_data)
        {
            i++;
            traverse = &arr[i];
        }
        Node *temp = traverse;
        while(traverse!=nullptr)
        {
            if(!obj.find_data(traverse->data))
            {
                cout<<traverse->data<<" ";
                obj.insert_node(traverse->data);
            }
            traverse = traverse->next;
        }
        traverse = temp;
        obj2.insert_node(traverse->data);
        while(traverse->next!=nullptr)
        {
            traverse=traverse->next;
            if(!obj2.find_data(traverse->data))
                BFS_traversal(traverse->data);
        }
    }
};

int main()
{
    Graph obj;
    int choice, data;
    while(choice!=5)
    {
        cout << "\n***********START*********";
        cout << "\nMAIN MENU\n1. Create the graph.\n2. Display graph.\n3. DFS traversal.\n4. BFS traversal.\n5. Exit.\n";
        cout << "Enter your choice:- ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            obj.create_graph();
            break;

        case 2:
            obj.display();
            break;

        case 3:
            cout<<"Enter the start:- ";
            cin>>data;
            obj.DFS_traversal(data);
            obj.obj.delete_SLL();
            break;

        case 4:
            cout<<"Enter the start:- ";
            cin>>data;
            obj.BFS_traversal(data);
            obj.obj.delete_SLL();
            obj.obj2.delete_SLL();
            break;

        case 5:
            cout<<"Thank you!";
            break;

        default:
            cout<<"Please enter a valid choice!";
            break;
        }
    }
    return 0;
}
