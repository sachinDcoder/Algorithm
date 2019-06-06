#include<bits/stdc++.h>
using namespace std;
int main()
{
    int total,n;
    cin>>total;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)
        cin>>coins[i];
    int t[total+1],r[total+1];
    for(int i=0;i<=total;i++)
    {
        t[i]=INT_MAX;
        r[i]=-1;
    }
    t[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=coins[i];j<=total;j++)
        {
            if(t[j-coins[i]]!=INT_MAX && t[j]>(t[j-coins[i]]+1))
            {
                t[j]=t[j-coins[i]]+1;
                r[j]=i;
            }
        }
    }

    int i=total;
    cout<<"coins are:"<<endl;
    while(i!=0)
    {
        cout<<coins[r[i]]<<endl;
        i=i-coins[r[i]];
    }
    /*for(int i=0;i<=total;i++)
        cout<<t[i]<<" ";
    cout<<endl;*/
    cout<<"Total: "<<t[total]<<endl;
    int table[total+1];
    memset(table, 0, sizeof(table));
    table[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=coins[i];j<=total;j++)
        {
            table[j]+=table[j-coins[i]];
        }
        /*for(int j=0;j<=total;j++)
            cout<<table[j]<<" ";
        cout<<endl;*/
    }
    cout<<"Ways: "<<table[total]<<endl;
    return 0;
}
