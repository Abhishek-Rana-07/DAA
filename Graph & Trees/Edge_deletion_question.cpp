#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int M=1e9+7;

vector<int> g[N];
int sum_sub[N];
int val[N];

void dfs(int vertex,int par)
{
    sum_sub[vertex] +=val[vertex];

    for(int  child : g[N])
    {
        if(child==par)   continue;
        dfs(child,vertex);
        sum_sub[vertex] += sum_sub[child];
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
    long long ans=0;
    for(int i=2;i<=n;i++)
    {
        int part1=sum_sub[i];
        int part2=sum_sub[1]-sum_sub[i];
        ans=max(ans,(part1 * 1LL * part2)%M);
    }

    cout<<ans;

}