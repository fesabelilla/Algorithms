#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>

using namespace std ;


int main()
{
    vector<int>arr;
    int N,K,flag = 0;

    while(cin>>N>>K)
    {
        flag = 0;
        for(int i = 0; i< N ; i++)
        {
            int a ;
            scanf("%d",&a);
            arr.push_back(a);
        }
        for(int i = 0; i< N-1 ; i++)
        {
            for(int j = i ; j<N; j++)
            {
                if(i!=j)
                {
                    if(arr[i]+arr[j]==K)
                    {
                        flag = 1;
                        break;
                    }

                }
            }
        }
        if(flag == 1)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

        arr.clear();
    }

    return 0;
}



