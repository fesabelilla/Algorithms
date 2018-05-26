/*
You are given




*/
#include<bits/stdc++.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

queue<int>  Q;
vector<int> adj[100];
vector<int> color[100];
vector<int> parent[100];
vector<int> distanc[100];
int edge;

void BFS(int SN, int n)
{
    for(int i=0; i<n+1; i++)
    {
        color[i].push_back(WHITE);
        parent[i].push_back(INT_MAX);
        distanc[i].push_back(INT_MAX);
    }
    distanc[SN].push_back(0); //Starting node = 0
    parent[SN].push_back(INT_MAX); //no parent

    Q.push(SN);

    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        color[x].pop_back();
        color[x].push_back(GRAY);
        cout<<x<<" ";

        int V = adj[x].size();
        for(int i=0; i<V; i++)
        {
            int adjN = adj[x].back();
            adj[x].pop_back();

            if(color[adjN][i]==WHITE)
            {
                parent[adjN].push_back(x);
                distanc[adjN].push_back(distanc[x].back()+1);
                Q.push(adjN);
            }
        }
        color[x].push_back(BLACK);
    }
}

int main()
{
    int n,a,b;
    cout<<"Enter the number of edges : ";
    cin>>edge;
    cout<<endl;

    cout<<"Enter the connected nodes : "<<endl;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<endl<<" Parent node  : "<<endl;
    cin>>n;
    BFS(n,edge+1);

    return 0;
}

