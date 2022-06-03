/* Hrishikesh Rajesh Menon -COE18B024

Logic:-  Greedy algorithm 1
    Set the lowest possible colorability of every vertix in the graph , and remove all vertices with colorablity with more than 1
    the memoisation is happening with the color of each vertex.
*/

#include <iostream> 
#include <queue> 
  
using namespace std; 

class Graph
{      
    public:
        bool** adjMatrix;
        int numVertices;
        int* colors;
          Graph(int numVertices) 
                {
                this->numVertices = numVertices;
                adjMatrix = new bool*[numVertices];
                colors= new int [numVertices];
                    for (int i = 0; i < numVertices; i++) 
                        {
                         adjMatrix[i] = new bool[numVertices];
                         for (int j = 0; j < numVertices; j++)
                            adjMatrix[i][j] = false;
                        }
                }
 
      void addEdge(int i, int j) 
        {
                  adjMatrix[i][j] = true;
                  adjMatrix[j][i] = true;
        }
 
      void removeEdge(int i, int j) 
        {
                  adjMatrix[i][j] = false;
                  adjMatrix[j][i] = false;
        }
 
      bool isEdge(int i, int j) {
                  return adjMatrix[i][j];
    }

      void removeVertex(int v)
        {
            for(int i=0;i<numVertices;i++)
            {
                removeEdge(v,i);
            }
        }

      void print() {
      for (int i = 0; i < numVertices; i++) {
                  cout << i << " : ";
                  for (int j = 0; j < numVertices; j++)
                        cout << adjMatrix[i][j] << " ";
                  cout << "\n";
      }
    }

    void colorrefresh()//color vertices with the lowest number of colors 
    {
        for (int i = 0; i < numVertices; ++i) 
        colors[i] = -1; 
  
        // Assign first color to source 
        colors[0] = 0; 
  


        bool available[numVertices]; 
        for (int cr = 0; cr < numVertices; cr++) 
            available[cr] = false; 
  
        // Assign colors to remaining V-1 vertices 
        for (int u = 1; u < numVertices; u++) 
         { 
        // Process all adjacent vertices and flag their colors 
        // as unavailable 
    
        for(int j=0;j<numVertices;j++)
            if(adjMatrix[u][j]==true && colors[j]!=-1)
                available[colors[j]]=true;

        // Find the first available color 
        int cr; 
        for (cr = 0; cr < numVertices; cr++) 
            if (available[cr] == false) 
                break; 
  
         colors[u] = cr;
        } 
    }

};


// This function returns true if graph  
// G[V][V] is Bipartite, else false 
bool isBipartite(Graph G) 
{ 

     int colorArr[G.numVertices]; 
    for (int i = 0; i < G.numVertices; ++i) 
        colorArr[i] = -1; 
  
    // Assign first color to source 
    colorArr[0] = 1; 
  
    queue <int> q; 
    q.push(0); 
  
    // Run while there are vertices in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        
        int u = q.front(); 
        q.pop(); 
  
        // Return false if there is a self-loop  
        if (G.adjMatrix[u][u] == 1) 
        return false;  
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < G.numVertices; ++v) 
        { 
            // An edge from u to v exists and  
            // destination v is not colored 
            if (G.adjMatrix[u][v] && colorArr[v] == -1) 
            { 
                // Assign alternate color to this adjacent v of u 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination  
            // v is colored with same color as u 
            else if (G.adjMatrix[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    }

    return true; 
}

    //Removes all uneccessary vertices using BFS Transversal
    Graph FindBipGraph(Graph G)
    {
         int visited[G.numVertices];

        for(int i = 0; i<G.numVertices; i++)
        {    
		visited[i] = false;
	    }

         if(isBipartite(G))
            return G;

        G.colorrefresh();

        queue<int> remove;
        
        for(int i=0;i<G.numVertices;i++)
        {
            cout<<"Colorability of vertex "<<i<<":-"<<G.colors[i]<<endl;           
        }   
        

        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            
            for(int v=0;v<G.numVertices;v++)
            {
                if(visited[v]==0 && G.adjMatrix[u][v])
                {
                    visited[v]=1;
                    q.push(v);
                    if(G.colors[v]>1)
                    remove.push(v);
                }
            }
           
        }

        while(!remove.empty())
            {
                G.removeVertex(remove.front());
                remove.pop();
            }

       return G;
    }

int main()
    {
         int choice;

          int n;
          cout<<"Enter the no of vertices:-"<<endl;
          cin>>n;

          int u,v;
          Graph G(n);
          Graph G1(n);
            do
            {
             cout<<"---------------MENU----------------"<<endl;
             cout<<"1.Add Edge"<<endl<<"2.Remove Edge"<<endl<<"3.Print Graph"<<endl;
             cout<<"4.Bipartite Maker"<<endl<<"5.Exit"<<endl;
             cout<<"Enter choice:-";
             cin>>choice;
             cout<<endl;

                switch(choice)
                {
                case 1:
                cout<<"Enter Vertix 1:-";
                cin>>u;
                cout<<"Enter Vertix 2:-";
                cin>>v;
                G.addEdge(u,v);
                break;

                case 2:
                cout<<"Enter Vertix 1:-";
                cin>>u;
                cout<<"Enter Vertix 2:-";
                cin>>v;
                G.removeEdge(u,v);
                break;

                case 3:
                G.print();
                break;

                case 4:
                G1=G;
                G1=FindBipGraph(G);
                cout<<"Bipartite Graph\n";
                G1.print();
                break;

                case 5:
                cout<<"Exited\n";
                break;
                }
            }while(choice!=5);
        return 0;
    }


