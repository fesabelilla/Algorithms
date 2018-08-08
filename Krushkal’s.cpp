#include<bits/stdc++.h>
#define MX 100

using namespace std;

int parent[MX];
int rankParent[MX];

struct edgeStructure{
 int u;
 int v;
 int w;
};

vector<edgeStructure> edgeVector;

bool operator<(edgeStructure lhs, edgeStructure rhs){
return lhs.w<rhs.w;
}

/*bool cmp(const edgeStructure &lhs, const edgeStructure &rhs){
if(lhs.u!=rhs.u)
    return lhs.u<rhs.u;
    else
        return lhs.w<rhs.w;
}*/

void initializseSet(int n){
 for(int i=0;i<n;i++){
    parent[i] = i;
    rankParent[i] = 0;
 }
}

int findParent(int x){
if(x!=parent[x])
    return parent[x] = findParent(parent[x]);
else
    return x;
}

void unionSet(int x,int y){
  int px = findParent(x);
  int py = findParent(y);
  if(px==py) return;

  if(rankParent[px] < rankParent[py] )
    parent[px] = py;
  else if(rankParent[px]>rankParent[py])
    parent[py] = px;
  else
  {
      parent[py] = px;
      rankParent[px]++;
  }

}

int Kruskal(int n){
 initializseSet(n);

sort(edgeVector.begin(),edgeVector.end());

int sz = edgeVector.size();

int ans = 0;

for(int i = 0;i<sz;i++){
    if(findParent(edgeVector[i].u) != findParent(edgeVector[i].v)){
        unionSet(parent[edgeVector[i].u],parent[edgeVector[i].v]);
        cout<<edgeVector[i].u<<" "<<edgeVector[i].v<<" "<<edgeVector[i].w <<endl;
        ans+=edgeVector[i].w;
    }
}
return ans;
}

int main()
{
    freopen("kruskal.txt","r",stdin);
    int vertex,edge;

    cin>>vertex>>edge;

    for(int i =0;i<edge;i++){
        edgeStructure e;
        cin>>e.u>>e.v>>e.w;
        edgeVector.push_back(e);
    }
  cout<<"MST Cost : "<< Kruskal(vertex)<<endl;
   return 0;
}
