#include<bits/stdc++.h>

#define white 1
#define gray 2
#define black 3

using namespace std;

vector<vector<int> > graph1;
vector<vector<int> > graph2;
vector<int> color;
stack<int> s;

int v,e;

void dfs_visit(int n)
{
    color[n] = gray;

    for(int i=0 ; i<graph1[n].size() ; i++)
    {
        int v = graph1[n][i];
        if(color[v] == white)
        {
            dfs_visit(v);
        }
    }

    color[n] = black;
    s.push(n);
}

void dfs(int sn)
{
    if(sn == white)
    {
        dfs_visit(sn);
    }

    for(int i=0 ; i<v ; i++)
    {
        if(color[i]==white)
        {
            dfs_visit(i);
        }
    }

}

void reverse_dfs_visit(int n)
{
    color[n] = gray;
    cout<<n<<" ";

    for(int i =0 ; i<graph2[n].size() ; i++)
    {
        int v = graph2[n][i];
        if(color[v] == white)
        {
            reverse_dfs_visit(v);
        }
    }
    color[n] = black;
}

void reverse_dfs(int sn)
{
    int i = 1;

    cout<<endl<<endl;
    cout<<i++<<" : ";

    if(color[sn] == white)
    {
        reverse_dfs_visit(sn);
    }

    while(!s.empty())
    {
        if(color[s.top()] == white)
        {
            cout<<endl;
            cout<<i++<<" : ";
            reverse_dfs_visit(s.top());
        }
        s.pop();
    }

}

int main()
{
    cout<<"Enter the number of vertex and edges : ";
    cin>>v>>e;

    graph1.assign(v,vector<int>());
    graph2.assign(v,vector<int>());
    color.assign(v,white);

    int n1,n2;

    cout<<"Enter edges : "<<endl;

    for(int i = 0 ; i < e ; i++)
    {
        cin>>n1>>n2;
        graph1[n1].push_back(n2);
        graph2[n2].push_back(n1);
    }

    dfs(0);
    color.assign(v,white);
    reverse_dfs(s.top());

    return 0;
}
