#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,m;
    cout<<"Enter the vertices and edges: ";
    cin>> N >> m;
    vector<pair<int , int>> adj[N];
    cout<<"Enter the edges: ";
    int a,b,wt;


    for(int i=0;i<m ; i++ )
    {
        cin>> a >> b >>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    int parent[N];

    int Key[N];

    int vis[N];

    for(int i=0; i<N ;i++)
    {
        Key[i]=INT_MAX, parent[i]=-1 , vis[i]=false;

    }

    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;

    Key[0]=0;
    parent[0] = -1;

    pq.push({0,0});

    for(int count=0; count<N-1 ;count++)
    {
        int u=pq.top().second;
        pq.pop();

        vis[u]=true;

        for(auto it : adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(vis[v]==false  && weight<Key[v])
            {
                parent[v]=u;
                pq.push({Key[v],v});
                Key[v]=weight;
                
            }
        }
    }
    int sum=0;
    for(int i=1;i<N; i++){
        cout<< parent[i] <<"--"<< i<<endl;
        sum+=Key[i];
    }

    cout<<"Sum of MST: "<<sum;
    
        
        
    return 0;

}