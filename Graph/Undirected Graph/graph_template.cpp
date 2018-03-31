//UNDIRECTED UNWEIGHTED GRAPH TEMPLATE
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
void showAdjList(vector<int> adjlist[], int n)
{
    size_t i,j;
    cout<<"\n\nNodes\t\t\tAdjcent Nodes\n\n";
    for(i=0;i<n;i++)
    {
        cout<<i<<"\t\t\t";
        for(j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j];
            if(adjlist[i].size()-j!=1)
                cout<<",";
        }
        if(j==0) cout<<"-";
        cout<<"\n";
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
        cout<<"\nEdge "<<E<<" between:\t"; cin>>from;
        cout<<"and:\t"; cin>>to;
        if(from>V||to>V)
        {
            cerr<<"Nodes are not defined for the edge.\nPlease check your inputs.";
            return -1;
        }
        addEdge(G,from,to);
    }
    showAdjList(G,V);
    return 0;
}
