// DIAMETER OF A TREE
// step 1: with any root find maximum depth node
// step 2: with that node as root find maximum depth

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
int depth[N];

void dfs(int v, int par=-1)
{
    for(int child : g[v])
    {
        if(child==par) continue;
        depth[child]=depth[v]+1;
        dfs(child,v);
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

     dfs(1);

     int max_depth=-1,depth_node;
     for(int i=1;i<=n;i++)
     {
         if(depth[i]>max_depth)
         {
             max_depth=depth[i];
             depth_node=i;
         }
         depth[i]=0;
     }
    

     dfs(depth_node);
    
     max_depth=-1;
     for(int i=1;i<=n;i++)
     {
         if(depth[i]>max_depth)
         {
             max_depth=depth[i];
         }
     }

     cout<<"Diameter: "<<max_depth;

 }