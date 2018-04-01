//UNDIRECTED UNWEIGHTED GRAPH DFS TRAVERSAL WITHOUT USING STACK
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#define pb push_back
#define fp first
#define sp second
using namespace std;
void addEdge(vector<int> adjlist[], int x, int y)
{
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
}
void DFS(vector<bool> &visited, vector<int> adjlist[],int u)
{
    visited[u]=true;
    cout<<"\n"<<u<<"\t";
    for(size_t i=0;i<adjlist[u].size();i++)
    {
        if(visited[adjlist[u][i]]==false)
        {
            DFS(visited,adjlist,adjlist[u][i]);
        }
    }
}
void callDFS(int n,vector<int> adjlist[])
{
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            DFS(visited,adjlist,i);
        }
    }
}
int main()
{
    int V,E,from,to;
    cout<<"\nGRAPH IMPLEMENTATION by Aditya Sahu\nDate:\t31-Mar-18\n";
    cout<<"\vEnter number of vertices:\t"; cin>>V;
    vector<int> G[V];
    cout<<"\nEnter number of edges:\t"; cin>>E;
    if(E>((V*(V-1))/2))
    {
        cerr<<"Check the number of edges";
        return -1;
    }
    system("cls");
    for(int i=0;i<E;i++)
    {
        cout<<"\nEdge "<<i+1<<" between:\t"; cin>>from; cout<<"and:\t"; cin>>to;
        if(from>V||to>V)
        {
            cerr<<"Nodes are not defined for the edge.\nPlease check your inputs.";
            return -1;
        }
        addEdge(G,from,to);
    }
    callDFS(V,G);
}
