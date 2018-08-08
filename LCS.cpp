#include<bits/stdc++.h>
using namespace std;

int max(int X, int Y)
{
    return (X > Y)? X : Y;
}
int lcs( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    for(i=1; i<=m; i++)
        L[i][0] = 0;
    for(j=1; j<=n; j++)
        L[0][j] = 0;

    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (X[i] == Y[j])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    int m = s1.length();
    int n = s2.length();

    char x[m+1],y[n+1];

    strcpy(x, s1.c_str());
    strcpy(y, s2.c_str());

    cout<<"Length of LCS is : "<<lcs( x, y, m, n );

    return 0;
}
