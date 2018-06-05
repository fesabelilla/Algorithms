#include<bits/stdc++.h>
#define white 1
#define gray 2
#define black 3
#define pb push_back

using namespace std;

vector<int> color;
vector<vector<int> > g;
int v,e;

void DFS_Visit(int s)
{
    color[s] = gray;
    cout<<" "<<s<<endl;

    for(int i=0;i<g[s].size();i++){
        int v = g[s][i];
        if(color[v]==white){
            DFS_Visit(v);
        }
    }
    color[s] = black;
}

void DFS(int SN)
{
    if(color[SN] == white )
        DFS_Visit(SN);

    for(int i = 0 ; i<v ; i++){
        if(color[i] == white){
            DFS_Visit(i);
        }
    }

}

int main()
{
    cout<<"Enter the number the edges and vertex : ";
    cin>>e>>v;
    color.assign(v,white);
    g.assign(v,vector<int>());
    int n1,n2;
    cout<<"Enter the edges : "<<endl;
    for(int i = 0 ; i<e ; i++){
        cin>>n1>>n2;
        g[n1].pb(n2);
        g[n2].pb(n1);
    }

    DFS(0);

    return 0;
}
