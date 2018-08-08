 #include<bits/stdc++.h>
using namespace std;

#define MAX 100001
#define INF INT_MAX
#define pir pair< int, int >
#define pb(x) push_back(x)

vector<pir > G[MAX];
int D[MAX];
stack<int> stk;
pir adjWeight;

int main()
{
    int i, u, v, w, sz, nodes, edges, starting;

    cout << "Enter the number of vertex and edges: ";
    cin >> nodes >> edges;
    int P[nodes+1];//p=predecessor
    cout << "Enter the edges with width : source destination weigth : \n";
    for (i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        adjWeight = make_pair(v, w);
        G[u].pb(pir(v, w));
    }
    cout << "Enter the source node: ";
    cin >> starting;
    for (i = 1; i <= nodes; i++)
        D[i] = INF;
    D[starting] = 0;

for(int i=0; i<nodes-1; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            for(int k=0; k<G[j].size(); k++)
            {

                 adjWeight = G[i][k];
                w = D[i]+adjWeight.second;
                if(D[adjWeight.first] >w)
                {
                    D[adjWeight.first] = w;
                    P[adjWeight.first] = i;
                }

            }
        }
    }

    bool flag = false;
    for(int i=0;i<nodes && !flag; i++)
    {
        for(int k=0; k<G[i].size(); k++)
        {
           adjWeight= G[i][k];
           w = D[i]+adjWeight.second;
            if(D[adjWeight.first] > w)
            {
               flag = true;
                break;
            }
        }
    }

     if(!flag)
    {
        for(int i=0; i<nodes; i++)
        {
            cout<< starting << " to " << i << " is " << D[i] << endl;
            cout << "The shortest path:";
            int   SN = i;//SN = successorNode
            while(P[SN] != SN)//p=predecessor
            {
                stk.push(SN);
                SN = P[SN];
            }
            stk.push(SN);
            while(stk.empty()!=true)
            {
                cout << " " << stk.top();
                stk.pop();
            }
            cout << endl;
        }
    }
    else
    {
        cout <<"Negative cycle "<< endl;
    }


    return 0;
}
