#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<limits.h>
#include<stdlib.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

struct node
{
	int data;
	int weight;
	int degree;

	struct node *next;
};

struct node* myinsert(int data, struct node *head, int w);
void printList(struct node *head);
void myDelete(int data,struct node *head);

struct node* myinsert(int data,  struct node *head, int w)
{
	struct node *myinsert=(struct node*)malloc(sizeof(struct node));
	myinsert->next = NULL;
	myinsert->data = data;
	myinsert->weight = w;
	if(head!=NULL)
	{
		myinsert->next = head->next;
		head->next = myinsert;
	}
	else
	{
		myinsert->next = NULL;
	 	return myinsert;
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

	//Graph()
	//{
		//for(int i=0; i<n; i++)
		//{
			//N[i] = NULL;
		//}
	//}

	void insertEdge(int n1, int n2, int w)
	{
		N[n1] = myinsert(n2, N[n1], w);
	}

	void deleteEdge(int n1,int n2)
	{
		myDelete(n2,N[n1]);
	}

	void print()
	{
		for(int i=0; i<n; i++)
		{
			cout<<i<<" ";
			printList(N[i]);
			cout<<endl;
		}
	}

};

vector<int> BFS_SPATH(Graph G, int s, bool flag)
{
	bool visited[G.n]; 
    for (int i = 0; i < G.n; i++) 
        visited[i] = false;
    vector<int> dist;
	vector<int> paths;
    for (int i = 0; i < G.n; i++)
    {
    	dist.push_back(0);
    	paths.push_back(1);
	}
    dist[s] = 0; 
    paths[s] = 1; 

    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    while (!q.empty()) 
    { 
        int curr = q.front(); 
        q.pop(); 

        // For all neighbors of current vertex do: 
        struct node* temp = G.N[curr];
        while(temp != NULL)
        { 
            // if the current vertex is not yet 
            // visited, then push it to the queue.
			int x = temp->data; 
            if (visited[x] == false) 
            { 
                q.push(x); 
                visited[x] = true; 
            } 

            // check if there is a better path. 
            if (dist[x] > dist[curr] + 1) 
            { 
                dist[x] = dist[curr] + 1; 
                paths[x] = paths[curr]; 
            } 

            // additional shortest paths found 
            else if (dist[x] == dist[curr] + 1) 
                paths[x] += paths[curr]; 
        }
    }
    return paths;
}

int main()
{
  	Graph G;
  	Graph K;
  	G.n = 9;
  	K.n = 9;
  	for(int i=0; i<G.n; i++)
	{
		G.N[i] = NULL;
	}
  	for(int i=0; i<K.n; i++)
	{
		K.N[i] = NULL;
	}

  	G.insertEdge(0,1,3);
    G.insertEdge(1,2,6);
    G.insertEdge(1,3,4);
    G.insertEdge(2,3,2);
    G.insertEdge(2,4,5);
    G.insertEdge(3,4,1);
    G.insertEdge(3,5,1);
    G.insertEdge(3,6,8);
    G.insertEdge(4,6,7);
    G.insertEdge(6,7,3);
    
    G.insertEdge(1,0,3);
    G.insertEdge(2,1,6);
    G.insertEdge(3,1,4);
    G.insertEdge(3,2,2);
    G.insertEdge(4,2,5);
    G.insertEdge(4,3,1);
    G.insertEdge(5,3,1);
    G.insertEdge(6,3,8);
    G.insertEdge(6,4,7);
    G.insertEdge(7,6,3);


	vector<int> V = BFS_SPATH(G, 0, false);
	for(int i = 0; i < V.size(); i++){
		cout<<V[i]<<endl;
	}

}
