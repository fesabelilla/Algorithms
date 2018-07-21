#include<bits/stdc++.h>

using namespace std;

#define MAX 100001
#define INF INT_MAX
#define pir pair< int, int >
#define pb(x) push_back(x)

struct comp
{
        bool operator()(const pir &a, const pir &b)
        {
            //cout<<a.second<<" > "<<b.second<<endl;
            return a.second > b.second;//10>60 //60>50
        }
};

priority_queue<pir, vector<pir > , comp> Q;//priority_queue<datatype,vector<datatype>,comparator>
vector<pir > G[MAX];
int D[MAX];
bool F[MAX];

int main()
{
    int i, u, v, w, sz, nodes, edges, starting;

    // create graph
    cout << "Enter the number of vertex and edges: ";
    cin >> nodes >> edges;
    cout << "Enter the edges with width : source destination weigth : \n";
    for (i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        G[u].pb(pir(v, w));
        G[v].pb(pir(u, w)); // for undirected
    }
    cout << "Enter the source node: ";
    cin >> starting;

    // initialize distance vector
    for (i = 1; i <= nodes; i++)
        D[i] = INF;
    D[starting] = 0;
    Q.push(pir(starting, 0));

    // dijkstra
    while (!Q.empty())
    {
        u = Q.top().first;
        Q.pop();
        cout<<u<<endl;
        if (F[u])
            continue;
        sz = G[u].size();
        for (i = 0; i < sz; i++)
        {
            v = G[u][i].first;
            cout<<v<<endl;
            w = G[u][i].second;
            cout<<w<<endl;
            if (!F[v] && D[u] + w < D[v])
            {
                D[v] = D[u] + w;
                cout<<D[v]<<endl;
                Q.push(pir(v, D[v]));
            }
        }
        F[u] = 1; // done with u visited
    }

    // result
    for (i = 1; i <= nodes; i++)
        cout << "Node " << i << ", min weight = " << D[i] << endl;
    return 0;
}
