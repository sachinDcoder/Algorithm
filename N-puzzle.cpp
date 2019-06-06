#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int SumLess(int a[],int n)
{
    int c=0;
    /*for(int i=0;i<n*n;i++)
        cout<<a[i]<<" ";
    cout<<endl;*/
    for(int i=0;i<(n*n-1);i++)
    {
        for(int j=i+1;j<(n*n);j++)
        {
            if(a[i]!=0 && a[j]!=0 && a[i]>a[j])
                c++;
        }
    }
    return c;
}
bool Npuzzle(int **a,int n,int r0)
{
    int a1[n*n];
    for(int i=0,x=0;i<n;i++)
        for(int j=0;j<n;j++)
            a1[x++]=a[i][j];
    int c=SumLess(a1,n);
    //cout<<c<<endl;
    if((n%2==1 && c%2==0) || (n%2==0 && r0%2==1 && c%2==0) || (n%2==0 && r0%2==0 && c%2==1))
        return 1;
    return 0;
}
int main()
{
    int n;
    cout<<"Enter the n in N-puzzle: ";
    cin>>n;
    int **a,r0=4;
    a=new int*[n];
    cout<<"Enter the initial state(0 for the blank space): ";
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
                r0=n-i;
        }
    }
    bool f=Npuzzle(a,n,r0);
    if(f==1)
        cout<<"Solvable"<<endl;
    else
        cout<<"Not Solvable"<<endl;
    return 0;
}
