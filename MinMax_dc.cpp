#include<iostream>
#include<climits>
using namespace std;
int findMin(int a[],int l,int u)//divide and conquer for finding minimum
{
    int x,m,y;
    m=(l+u)/2;
    if(l==u)
        return a[l];
    x=findMin(a,l,m);
    y=findMin(a,m+1,u);
    return (x<y?x:y);
}
int findMax(int a[],int l,int u)//divide and conquer for finding maximum
{
    int x,m,y;
    m=(l+u)/2;
    if(l==u)
        return a[l];
    x=findMax(a,l,m);
    y=findMax(a,m+1,u);
    return (x>y?x:y);
}
int findMin(int a[],int n)
{
    int minm=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(minm>a[i])
            minm=a[i];
    }
    return minm;
}
int findMax(int a[],int n)
{
    int maxm=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(maxm<a[i])
            maxm=a[i];
    }
    return maxm;
}
int main()
{
    int n,i,j,minm,maxm;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    minm=findMin(a,0,n-1);

    maxm=findMax(a,0,n-1);
    cout<<"Minimum is "<<minm<<endl;
    cout<<"Maximum is "<<maxm<<endl;
    cout<<"Using dp"<<endl;
    cout<<"Minimum is "<<findMin(a,n)<<endl;
    cout<<"Maximum is "<<findMax(a,n)<<endl;
    return 0;
}
