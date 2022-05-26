//Topological sort
#include<iostream>
#define MAX 20
#define SIZE 100
using namespace std;

class Graph
{
    int g[MAX][MAX], n;

public:
    Graph(int n=0)
    {
        this->n = n;
    }

    void read_graph()
    {
        int i,j;
        cout<<"Enter the number of vertices:- ";
        cin>>n;
        cout<<"Enter the adjacency matrix:- \n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    cout<<"Enter indegree for "<<i<<" to "<<j<<":- ";
                    cin>>g[i][j];
                }
                else
                    g[i][j] = 0;
            }
        }
    }

    void display()
    {
        int i, j;
        cout<<0<<" ";
        for(i=0;i<n;i++)
            cout<<i<<" ";
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<i<<" ";
            for(j=0;j<n;j++)
            {
                cout<<g[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void topological_sort()
    {
        int visited[MAX], indegree[MAX];
        int i, j;
        //
        for(i=0;i<n;i++)
        {
            visited[i]=0;
            indegree[i]=0;
            for(j=0;j<n;j++)
            {
                if(g[j][i] != 0)
                    indegree[i]++;
            }
        }
        cout<<"Topological Ordering Sequence:\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(visited[j]==0 && indegree[j]==0)
                {
                    cout<<j<<" ";
                    //decrement the indegree of nodes adjacent to
                    visited[j] = 1;
                    for(int k=0;k<n;k++)
                    {
                        if(g[j][k]!=0)
                            indegree[k]--;
                    }
                    break;
                }
            }
            if(j==n)
            {
                cout<<"Graph has a cycle!";
                break;
            }
        }
    }
};

int main()
{
    Graph obj;
    obj.read_graph();
    obj.display();
    obj.topological_sort();
    return 0;
}
