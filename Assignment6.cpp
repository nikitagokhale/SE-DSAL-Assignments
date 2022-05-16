/* Represent a given graph using adjacency list to perform DFS and BFS. Use the map of the area
 around the college as the graph. Identify the prominent landmarks as nodes and perform DFS
 and BFS on that.*/

 #include <iostream>
using namespace std;

class Nodever{
int destver;
Nodever *next;
public:
Nodever(){
destver=-1;
next=NULL;
}
Nodever(int destver){
this->destver=destver;
next=NULL;
}
friend class Graph;
};

class Stack{
int top;
int arrst[10];
public:
Stack(){
top=-1;
for(int i=0;i<10;i++){
arrst[i]=0;
}
}
void push(int v){
top++;
arrst[top]=v;
}
int pop(){
int v=arrst[top];
top--;
return v;
}
bool isEmpty(){
if(top==-1){
return true;
}
return false;
}
friend class Graph;
};

class Queue{
int front,rear;
int arrqu[10];
public:
Queue(){
front=-1;
rear=-1;
for(int i=0;i<10;i++){
arrqu[i]=0;
}
}
void enqueue(int v){
if(front==-1){
front+=1;
}
rear+=1;
arrqu[rear]=v;
}

int dequeue(){
if(front>rear){
return -1;
}
int v=arrqu[front];
front+=1;
return v;
}
bool isEmpty(){
if(front>rear){
return true;
}
return false;
}
friend class Graph;
};

class Graph{
int nver,nedges;
Nodever **graphpt;
public:
Graph(){
cout<<"\nEnter the Number of Vertices -----> ";
cin>>nver;
cout<<"\nEnter the Number of Edges -----> ";
cin>>nedges;
graphpt=new Nodever *[nver];
for(int i=0;i<nver;i++){
graphpt[i]=NULL;
}
}
Graph(int nver,int nedges){
this->nver=nver;
this->nedges=nedges;
graphpt=new Nodever *[nver];
for(int i=0;i<nver;i++){
graphpt[i]=NULL;
}
}
void insert_edges(){
for(int i=0;i<nedges;i++){
int x,y;
cout<<"\nEnter vertices having edge between them -----> ";
cin>>x>>y;
Nodever *t=graphpt[x];
Nodever *t1=new Nodever(y);
if(t==NULL){
graphpt[x]=t1;
}
else{
while(t->next){
t=t->next;
}
t->next=t1;
}
}
}

void display(){
   cout<<"\n----------------DISPLAY GRAPH----------------\n"<<endl;
for(int i=0;i<nver;i++){
Nodever *p=graphpt[i];
cout<<" [ "<<i<<" ]";
while(p){
cout<<" ---> [ "<<p->destver<<" ] ";
p=p->next;
}
cout<<"\n";
}
}

void disp_bfs(){
int v;
cout<<"\nEnter Starting Vertex for BFS Traversal -----> ";
cin>>v;
bool visitedNodes[nver];
Queue q;
for(int i=0;i<nver;i++){
visitedNodes[i]=false;
}
Nodever *p=graphpt[v];
cout<<" [ "<<v<<" ] ";
visitedNodes[v]=true;
q.enqueue(v);
while(!q.isEmpty()){
int k=q.dequeue();
if(visitedNodes[k]==false){
cout<<"---> [ "<<k<<" ] ";
visitedNodes[k]=true;
}
p=graphpt[k];
while(p){
if(visitedNodes[p->destver]==false){
q.enqueue(p->destver);
}
p=p->next;
}
}
}

void disp_dfs(){
int v;
cout<<"\nEnter Starting Vertex for DFS Traversal -----> ";
cin>>v;
bool visitedNodes[nver];
for(int i=0;i<nver;i++){
visitedNodes[i] = 0;
}
Stack s;
Nodever *p=graphpt[v];
cout<<" [ "<<v<<" ] ";
visitedNodes[v]=true;
s.push(v);
while(!s.isEmpty()){
int k=s.pop();
if(visitedNodes[k]==false){
cout<<"---> [ "<<k<<" ] ";
visitedNodes[k]=true;
}
p=graphpt[k];

while(p){
if(visitedNodes[p->destver]==false){
s.push(p->destver);
}
p=p->next;
}
}


}



};

int main() {

Graph a;

int ch;
while(ch!=5){
cout<<"\n\n----------------MAIN MENU-----------------\n\n";
cout<<"1) Insert Edges"<<endl;
cout<<"2) Display Adjacency List"<<endl;
cout<<"3) Display Graph using DFS"<<endl;
cout<<"4) Display Graph using BFS"<<endl;
cout<<"5) Exit"<<endl;
cout<<"\n------------------------------------------\n";

cout<<"\nEnter your choice -----> ";
cin>>ch;

switch(ch){
case 1:
a.insert_edges();
break;
case 2:
a.display();
break;
case 3:
a.disp_dfs();
break;
case 4:
a.disp_bfs();
break;
case 5:
cout<<"\nThank you!!!!!";
break;
}
}

return 0;
}

