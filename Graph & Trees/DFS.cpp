#include<bits/stdc++.h>
using namespace std;
//complexity O(V+E)
const int N=1e5+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex)
{  
    //  Take action on vertex after entering the vertex
    cout<< vertex<<endl;
    vis[vertex]= true;
    for(int child : g[vertex] )
    {
        
        // Take action on child before entering the child node 
        cout <<"par "<<vertex<<", child "<<child << endl;
        if(vis[child])
             continue;
        dfs(child);
         // Take action on child after entering the child node 
    }
    // Take action on vertex before exiting the vertex 
}

int main()
{
    int n,m,vertex;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the nuber of edges: "<<endl;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>> v1 >>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    cout<<"Enter the starting point of vertex: "<<endl;
    cin>>vertex;
    dfs(vertex);
}