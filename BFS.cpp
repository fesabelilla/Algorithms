/*
In this code node start with 0.
So given input is
0 1
0 2
1 3
1 4
2 5
2 6
*/

#include<bits/stdc++.h>
#define pb push_back
#define t true
#define f false

using namespace std;

vector<bool>v;
vector<vector<int> >g;

void BFS(int s)
{
    queue<int>q;
    q.push(s);
    v[s] = t;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        cout<<u<<" ";

        for(int i=0 ; i<g[u].size() ; i++){
            if(!v[g[u][i]]){
                int k = g[u][i];
                v[k] = t;
                q.push(k);
            }
        }
    }
}



int main()
{
    int n,e;
    cout<<"Enter the number of nodes :";
    cin>>n;
    cout<<"Enter the number of edges :";
    cin>>e;

    v.assign(n,f);
    g.assign(n,vector<int> ());

    int n1,n2,s;

    for(int i=0 ; i<e ; i++){
        cin>>n1>>n2;
        g[n1].pb(n2);
        g[n2].pb(n1);
    }
    cout<<"Enter the starting node : ";
    cin>>s;

    BFS(s);



return 0;
}
