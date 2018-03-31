//UNDIRECTED GRAPH DFS TRAVERSAL
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
    int n,e,from,to;
    cout<<"\nGRAPH IMPLEMENTATION by Aditya Sahu\nDate:\t31-Mar-18\n";
    cout<<"\vEnter number of vertices:\t"; cin>>n;
    vector<int> v[n];
    cout<<"\nEnter number of edges:\t"; cin>>e;
    if(e>((n*(n-1))/2))
    {
        cerr<<"Check the number of edges";
        return -1;
    }
    system("cls");
    while(e--)
    {
        cout<<"\nEdge between:\t"; cin>>from; cout<<"and:\t"; cin>>to;
        addEdge(v,from,to);
    }
    callDFS(n,v);
    return 0;
}
