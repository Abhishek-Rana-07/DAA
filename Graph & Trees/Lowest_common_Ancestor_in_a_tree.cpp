#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
int  par[N];

void  dfs(int v,int p=-1)
{
    
    par[v]=p;
    for(int child: g[v])
    {
        if(child==p)  continue;
        dfs(child,v);
    }
}

vector<int>  path(int v)
{
    vector<int> ans;
    
    while(v!= -1)
    {
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
        
    dfs(1);
    
    int x,y;
    cin>>x>>y;
    vector<int> first_node=path(x);
    vector<int> second_node=path(y);
    int mn=min(first_node.size(),second_node.size());
    
    int lca=-1;

    for(int i=0;i<mn;i++)
    {
        if(first_node[i]==second_node[i])
        {
            lca=first_node[i];
        }
        else
            break;
    }

    cout<<"Lowest common ancestor: "<<lca<<endl;
}