#include<bits/stdc++.h>
#include<string.h>
//dynamic approach
using namespace std;
//int g[100];
void printElements(int a[],int p[],int n,int i)
{
    if(p[i]==-1 || i>=n || i<0)
        return ;
    printElements(a,p,n,p[i]);
    if(p[i]<n)
        cout<<a[p[i]]<<" ";
}
void lisq(int n,int a[])
{
    int t[n],bestEnd=0,p[n];
    int maxm=INT_MIN;
    for(int i=0;i<n;i++)
    {
        p[0]=-1;
        t[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && t[i]<t[j]+1)
            {
                t[i]=t[j]+1;
                p[i]=j;
            }
        }
        if(maxm<t[i])
        {
            maxm=t[i];
            bestEnd=i;
        }
    }
    /*for(int i=0;i<n;i++)
        cout<<t[i]<<" ";
    cout<<endl;*/
    cout<<"Length of the longest increasing subsequence is "<<maxm<<endl;
    cout<<"The subsequence is : ";
    printElements(a,p,n,bestEnd);
    cout<<a[bestEnd];
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        //g[i]=a[i];
    }
    lisq(n,a);
    return 0;
}
/*Input  : arr[] = 3 10 2 1 20
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input  : arr[] = {3, 2}
Output : Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input : arr[] = 50 3 10 7 40 80
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}*/



//try to solve it in n log n
