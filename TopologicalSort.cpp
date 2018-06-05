#include<bits/stdc++.h>
#define white 1
#define gray 2
#define black 3
#define pb push_back

using namespace std;
void print();
vector<int> color;
vector<vector<int> > G;
stack<int> S;

int e,n;

void DFS_Visit(int SN)
{
    color[SN] == gray ;

    for(int i=0;i<G[SN].size();i++){
    int a = G[SN][i];
    if(color[a]== white){
        DFS_Visit(a);
    }
 }
color[SN] = black;

   S.push(SN);
}



void DFS(int SN)
{
    if(color[SN]== white)
        DFS_Visit(SN);

        for(int i=0;i<n;i++){
            if(color[i]==white)
                DFS_Visit(i);
        }

}


int main()
{
    cout<<"Enter edges and nodes number : ";
    cin>>e>>n;

    color.assign(n,white);
    G.assign(n,vector<int>());

    int n1,n2;

    cout<<"Enter edges : "<<endl;
    for(int i=0;i<e;i++){
        cin>>n1>>n2;
        G[n1].pb(n2);
       // G[n2].pb(n1);
    }
    DFS(0);
   cout<<"Topological sorting order : ";
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;

}
