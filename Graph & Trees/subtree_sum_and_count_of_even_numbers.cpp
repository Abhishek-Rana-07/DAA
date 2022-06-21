#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+10;

vector<int> g[N];
int sum_subtree[N];
int even_count[N];

void dfs(int vertex,int par=0)
{
    
    if(vertex % 2==0) {
        even_count[vertex]++;}
        

    sum_subtree[vertex] +=vertex;
    for(int child: g[vertex])
    {
        if(child==par)   continue;

        dfs(child,vertex);
        sum_subtree[vertex]+=sum_subtree[child];
        even_count[vertex]+=even_count[child];
    }
}

int main()
{
    int n;
    cout<<"Enter the number of vertices: "<<endl;;
    cin>>n;
    cout<<"Enter the tree"<<endl;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>> x >>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    

    dfs(1);

    for(int i=1;i<=n;i++)
    {
        cout<<sum_subtree[i]<<" "<<even_count[i]<<endl;
    }

}