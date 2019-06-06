#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,r;
    cout<<"Enter the n in nCr: ";
    cin>>n;
    cout<<"Enter the r in nCr: ";
    cin>>r;
    int b[n+1][r+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,r);j++)
        {
            if(i==j || j==0)
                b[i][j]=1;
            else
                b[i][j]=b[i-1][j-1]+b[i-1][j];
        }
    }
    cout<<n<<"C"<<r<<" = "<<b[n][r]<<endl;
    return 0;
}
