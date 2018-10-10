#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int>q;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(a);
    }

    while(!q.empty()){
        int p = q.top();
        q.pop();
        cout<<-p<<" ";
    }




    return 0;
}

