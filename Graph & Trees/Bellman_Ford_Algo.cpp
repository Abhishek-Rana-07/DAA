#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+10;
struct node
{
    int u,v,wt;
    node(int first,int second, int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};


int main()
{
    int v,e;
    cin>> v >> e;
    vector<node> edge;
    for(int i=0;i<e;i++)
    {
        int u ,v ,wt;
        cin>>u>> v >> wt;
        edge.push_back(node(u, v ,wt));
    }

    int src;
    cin>>src;

    vector<int> dist(v,INF);

    dist[src] = 0;

    for(int i=1;i<=v-1;i++)
    {
        for(auto it: edge)
        {
            if(dist[it.u] + it.wt <dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl=0;
    for(auto it : edge)
    {
        if(dist[it.u] + it.wt < dist[it.v])
        {
            cout<<" Negative Cycle";
            fl=1;
            break;
        }
    }

    if(!fl)
    {
        for(int i=0 ; i<v ; i++){
            cout<< i <<" "<< dist[i]<<endl;
        }
    }
    return 0;
}