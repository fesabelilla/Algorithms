#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> mp;

    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        string str;
        int a;

        cin>>str>>a;
        mp[str] = a;
    }

    string query;

    cin>>query;

    if(mp[query]){
        if(mp[query]>=80){
            cout<<"A+"<<endl;
        }else{
        cout<<"Not A+"<<endl;
        }
    }else{
    cout<<"NO STUDENT RECORD AVAILABLE"<<endl;
    }

    return 0;
}
