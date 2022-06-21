#include<bits/stdc++.h>
using namespace std;

// When the weights are not given
const int N= 1e3+10;
int graph1[N][N]; // For adjacency Matrix

vector<int> graph2[N]; //For adjacency Lists

int main()
{
    int n,m;
    cout<<"Enter the nuber of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    for(int i=0; i<m ;i++)
    {
        int v1,v2;
        cin>> v1 >> v2;
        graph1[v1][v2]=1;                    //This is for 
        graph1[v2][v1]=1;                    //Adjacency Matrix


        graph2[v1].push_back(v2);            //This is for
        graph2[v2].push_back(v1);            //Adjacency Lists
    }
}

// -----------------------------------------------------------------

// Adjacency Matrix 
// O(N^2) -   Space Complexity
// N=10^5

// Adjacency List
// O(N+M) - Space Complexity

//--------------------------------------------------------------------

// When the weights are given
const int N= 1e3+10;
int graph1[N][N]; // For adjacency Matrix

vector<pair<int,int>> graph2[N]; //For adjacency Lists

int main()
{
    int n,m;
    cout<<"Enter the nuber of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    for(int i=0; i<m ;i++)
    {
        int v1,v2,wt;
        cin>> v1 >> v2 >>wt;
        graph1[v1][v2]=wt;                    //This is for 
        graph1[v2][v1]=wt;                    //Adjacency Matrix


        graph2[v1].push_back({v2,wt});            //This is for
        graph2[v2].push_back({v1,wt});            //Adjacency Lists
    }
}