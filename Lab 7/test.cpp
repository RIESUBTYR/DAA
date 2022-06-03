#include<iostream>
 using namespace std;

 struct node{
 	struct node *next;
 	int data;
 	int weight;
 };

struct node* insert(struct node* head, int new_data,int new_weight) 
{ 
  
    struct node  *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data=new_data;
    new_node->weight=new_weight;

    if(head!=NULL)
    {
    new_node->next=head->next;
    head->next=new_node;
    }
    else
    {
    	new_node->next=NULL;
    	return new_node;
    }
    return head;
} 




 class Graph
 {
    public:

 	 int n;
 	 
 	 struct node* Head[1000];


 	 Graph(int size)
 	 {
 	 	n=size;
 	 	for(int i=0;i<n;i++)
 	 	{
 	 		Head[i]=NULL;
 	 	}

 	 }


 	 void insertEdge(int n1,int n2,int weight)
 	 {
 	 	Head[n1]=insert(Head[n1],n2,weight);
 	 	Head[n2]=insert(Head[n2],n1,weight);
 	 } 

 	 void print()
 	 {
 	 	for(int i=0;i<n;i++)
 	 	{
 	 		struct node* ptr=Head[i];
 	 		cout<<"VERTEX["<<i<<"]-->";
 	 		while(ptr!=NULL)
 	 		{
 	 			cout<<ptr->data<<"-->";
 	 			ptr=ptr->next;
 	 		}	
 	 		cout<<endl;
 	 	}
 	 }

 };


 int main()
 {
 	Graph g(5);

 	g.insertEdge(0,1,5);
 	g.insertEdge(0,2,5);
 	g.insertEdge(0,3,5);
 	g.insertEdge(0,4,5);
 	g.insertEdge(1,2,5);
 	g.insertEdge(3,4,5);
 	g.print();

 }

