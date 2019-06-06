#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
bool sort_by(const pair<int,int>& a,const pair<int,int>& b)
{
    return ((double)a.first/a.second > (double)b.first/b.second);
}
double FractionalKnapsack(int wt[],int val[],int n,int W)
{
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
        v.push_back(make_pair(val[i],wt[i]));
    sort(v.begin(),v.end(),sort_by);
    /*for(int i=0;i<n;i++)
        cout<<(double)v[i].first/v[i].second<<" ";
    cout<<endl;*/
    int tempW=0;
    double max_value=0.0;
    for(int i=0;i<n;i++)
    {
        int x=tempW+v[i].second;
        if(x<W)
        {
            tempW+=v[i].second;
            max_value+=v[i].first;
        }
        else
        {
            int r=W-v[i].second;
            max_value+=(double)v[i].first*r/v[i].second;
            break;
        }
    }
    return max_value;
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
    cout<<"Enter the total weight: ";
    cin>>W;
    int x=FractionalKnapsack(wt,val,n,W);
    cout<<"Maximum value can be obtained: "<<x<<endl;
    return 0;
}
