#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void sieveAlgo(ll n)
{
    bool isprime[n+1];
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(ll i=2;i*i<=n;i++)
    {
        if(isprime[i]==true)
        {
            for(ll j=i*2;j<=n;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(isprime[i]==true)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    sieveAlgo(n);
    return 0;
}
