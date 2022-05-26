//Heap sort
#include<iostream>
#define SIZE 30
using namespace std;

class Heap_sort
{
    int heap[SIZE];

public:
    void create()
    {
        int data, n;
        cout<<"Enter the number of elements:- ";
        cin>>n;
        cout<<"Enter data:- "<<endl;
        heap[0]=0;
        for(int i=0;i<n;i++)
        {
            cout<<">";
            cin>>data;
            insert_element(heap, data);
        }
    }

    void insert_element(int heap[], int data)
    {
        int n=heap[0];
        heap[n+1]=data;
        heap[0]=n+1;
        upAdjust(heap, n+1);
    }

    void upAdjust(int heap[], int i)
    {
        int temp;
        while(i>1 && heap[i]>heap[i/2])
        {
            temp = heap[i/2];
            heap[i/2]=heap[i];
            heap[i]=temp;
            i = i/2;
        }
    }

    void display_heap()
    {
        cout<<"Number of elements:- "<<heap[0]<<endl;
        for(int i=1;i<=heap[0];i++)
            cout<<heap[i]<<" ";
    }

    void heap_sort()
    {
        int n=heap[0], top=heap[0];
        for(int i=0;i<n-1;i++)
        {
            int temp = heap[top];
            heap[top] = heap[1];
            heap[1] = temp;
            top--;
            downAdjust(heap, top, 1);
        }
    }

    void downAdjust(int heap[], int n, int i)
    {
        int flag = 1, j;
        while(2*i<=n && flag)
        {
            j=i*2;
            if(j+1<=n && heap[j]<heap[j+1])
                j++;
            if(heap[i]>heap[j])
                flag = 0;
            else
            {
                int temp=heap[j];
                heap[j]=heap[i];
                heap[i]=temp;
                i=j;
            }
        }
    }
};

int main()
{
    Heap_sort obj;
    obj.create();
    cout<<"Before sorting!\n";
    obj.display_heap();
    obj.heap_sort();
    cout<<"\nAfter sorting!\n";
    obj.display_heap();
    return 0;
}
