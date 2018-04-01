//UNDIRECTED UNWEIGHTED GRAPH DFS TRAVERSAL USING STACK
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#define pb push_back
#define fp first
#define sp second
using namespace std;
void AddEdge(int x, int y, vector<int> adjlist[])
{
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
}
void DFS(int i, vector<bool> &visited, vector<int> adjlist[])
{
    stack<int> dfs_stack;
    dfs_stack.push(i);
    visited[i]=true;
    cout<<i<<"\t";
    dfs_stack.pop();
    for(int j=0;j<adjlist[i].size();j++)
    {
            dfs_stack.push(adjlist[i][j]);
    }
    if(!dfs_stack.empty())
    {
        if(visited[dfs_stack.top()]==false)
        {
            DFS(dfs_stack.top(),visited,adjlist);
        }
    }
}
void DFScall(int n, vector<int> adjlist[])
{
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            DFS(i,visited,adjlist);
    }
}
int main()
{
    int V,E,from,to;
    cout<<"\nGRAPH IMPLEMENTATION by Aditya Sahu\nDate:\t31-Mar-18\n";
    cout<<"Enter the number of vertices:\t"; cin>>V;
    vector<int> G[V];
    cout<<"\nEnter the number of edges:\t"; cin>>E;
    if(E>((V*(V-1))/2))
    {
        cout<<"\nCheck the number of edges.";
        return -1;
    }
    system("cls");
    for(int i=0;i<E;i++)
    {
        cout<<"\nEdge "<<i+1<<" between:\t"; cin>>from;
        cout<<"and:\t"; cin>>to;
        if(from>V||to>V)
        {
            cout<<"\nNot enough nodes for the edge inputted.\nPlease check the edge.";
            return -1;
        }
        AddEdge(from,to,G);
    }
    DFScall(V,G);
    return 0;
}
