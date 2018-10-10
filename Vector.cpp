#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t;
    cin>>t;
    for(int i=0;i<t;i++){
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int oddSum = 0, evenSum = 0;

    for(int i=0 ; i<v.size() ;i++){
        if(v[i]%2==0){
            evenSum+=v[i];
        }
        else{
            oddSum+=v[i];
        }
    }
    if(oddSum>evenSum){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}


    return 0;
}
