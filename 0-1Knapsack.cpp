#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
int knapsack(int wt[],int val[],int n,int W)
{
    int ks[n+1][W+1];
    set<pair<int,int> > s;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                ks[i][j]=0;
            else if(wt[i-1]>j)
                ks[i][j]=ks[i-1][j];
            else
                ks[i][j]=max(ks[i-1][j],val[i-1]+ks[i-1][j-wt[i-1]]);
        }
    }
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
            cout<<ks[i][j]<<" ";
        cout<<endl;
    }*/
    for(int i=n,j=W;i>0 && j>0;i--)
    {
        if(ks[i][j]!=ks[i-1][j])
        {
            s.insert(make_pair(val[i-1],wt[i-1]));
            j=j-wt[i-1];
        }
    }
    set<pair<int,int> >::iterator it;
    if(s.size()>=1)
    {
        cout<<"\nSelected items are:"<<endl;
        printf("%7s %7s\n","value","weight");
        for(it=s.begin();it!=s.end();it++)
        {
            printf("%7d %7d\n",(*it).first,(*it).second);
        }
    }
    return ks[n][W];
}
int main()
{
    int n,W;
    cout<<"Enter the number of items:";
    cin>>n;
    int val[n],wt[n];
    cout<<"Enter the weight and value of the corresponding item:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"value["<<i<<"]=";
        cin>>val[i];
        cout<<"weight["<<i<<"]=";
        cin>>wt[i];
        cout<<endl;

    }
    cout<<"Enter the total weight:";
    cin>>W;
    int x=knapsack(wt,val,n,W);
    cout<<"Maximum value can be obtained: "<<x<<endl;
    return 0;
}
