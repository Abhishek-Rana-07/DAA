// Two Optimization
// 1. Union by Size or Rank
// 2. Path compression
#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;

int parent[N];
int size[N];

void make(int v)
{
    parent[v]=v;
    size[v]=1;
}

int find(int v)
{
    if(v==parent[v])  return v;
    // Path compression
    return parent[v]=find(parent[v]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(size[a]<size[b])    //Union by Size
            swap(a,b);
        parent[b]=a;
        size[a] +=size[b];
    }
}

// The time complexity after using 
// 1. Union by size and,
// 2. Path compression
// will be:-

// O(_ALPHA(n))

// most of the time for any value of 'n' it is found that 
// the value of       Aplha(n)  is not greater than 4

int main()
{
    int n,k;
    cin >> n>>k;
    for(int i=1; i<=n; i++)
    {
        make(i);
    }
    while(k--)
    {
        int u,v;
        cin>> u >>v;
        Union(u,v);
    }

    int connected_ct=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==i)  connected_ct++;
    }
    cout<<"count: "<<connected_ct;
}
