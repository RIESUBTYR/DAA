#include<iostream>

using namespace std;

struct node
{
	int data;
	int weight;
	
	struct node *next;
};

struct node* insert(int data,  struct node *head, int w)
{
	struct node *insert=(struct node*)malloc(sizeof(struct node));
	insert->data = data;
	insert->weight = w;
	 if(head!=NULL)
	 {
	 	insert->next = head->next;
	 	head->next = insert;
	 }
	 else
	 {
	 	insert->next = NULL;
	 	return insert;
	 }
	 
	 return head;
	
}

void printList(struct node *head)
{
	struct node *temp = head;
	
	while(temp!=NULL)
	{
		cout << temp->data << "  ";
		temp = temp->next;	
	}
} 

class Graph
{
	public : 
	int n;
		
	struct node *N[100];
	
	Graph()
	{
		for(int i=0; i<n; i++)
		{
			N[i] = NULL;
		}
	}
	
	void insertEdge(int n1, int n2, int w)
	{
		N[n1] = insert(n2, N[n1], w);
		N[n2] = insert(n1, N[n2], w);
	}
	
	void print()
	{
		for(int i=0; i<n; i++)
		{
			printList(N[i]);
			cout<<endl;
		}
	}
	
};

int main()
{
	Graph g;
	
	g.n = 5;
	
	g.insertEdge(0,1, 2);
	g.insertEdge(2,1, 21);
	g.insertEdge(1,3, 20);
	g.insertEdge(4,2, 88);
	
	cout << endl;
	
	g.print();
	
		
}
