#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int maxmCrossOver(int a[],int l,int m,int h)
{
    int lsum=INT_MIN,rsum=INT_MIN,tsum=0;
    for(int i=m;i>=l;i--)
    {
        tsum+=a[i];
        if(lsum<tsum)
        {
            lsum=tsum;
            //cout<<a[i]<<" ";
        }
    }
    tsum=0;
    for(int i=m+1;i<=h;i++)
    {
        tsum+=a[i];
        if(rsum<tsum)
        {
            rsum=tsum;
            //cout<<a[i]<<" ";
        }
    }
    //cout<<endl;
    return lsum+rsum;
}
int maxSum(int a[],int l,int h)
{
    if(l==h)
        return a[l];
    int m=(l+h)/2;
    return max(maxmCrossOver(a,l,m,h),max(maxSum(a,l,m),maxSum(a,m+1,h)));
}
int main()
{
    int i,n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Maximum Sum: "<<maxSum(a,0,n-1)<<endl;
    return 0;
}
//12 -13 -5 25 -20 30 10
/*12 25 30 10
-20 30 10
-20 30
12 25
-5 25
12*/
