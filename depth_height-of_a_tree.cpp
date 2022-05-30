#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<int>  g[N];
int height[N];
int depth[N];

void dfs(int vertex,int par)
{
       for(int  child: g[vertex])
       {
             if(child==par)    continue;
             depth[child]=depth[vertex]+1;
             dfs(child,vertex);
             height[vertex]=max(height[vertex],height[child]+1);
       }       
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

     dfs(1,0);    
}
