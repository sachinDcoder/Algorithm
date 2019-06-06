//using complete stl
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
bool sort_by(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b)
{
    return (a.second.second < b.second.second);
}
set<pair<int,pair<int,int>> > activitySelection(vector<pair<int,pair<int,int>> > A)
{
    sort(A.begin(),A.end(),sort_by);
    vector<pair<int,pair<int,int>> >:: iterator it;
    /*for(it=A.begin();it!=A.end();it++)
        cout<<(*it).second.first<<" "<<(*it).second.second<<endl;*/
    set<pair<int,pair<int,int>> > s;
    s.insert(A[0]);
    int j=0;
    for(int i=1;i<A.size();i++)
    {
        if(A[i].second.first>=A[j].second.second)
        {
            s.insert(A[i]);
            //cout<<A[i].first<<" ";
            j=i;
            //cout<<endl<<"j:"<<j<<" "<<endl;
        }
    }
    return s;
}
int main()
{
    int n,job_no,start_time,finish_time;
    cout<<"Enter the number of Jobs: ";
    cin>>n;
    vector<pair<int,pair<int,int>> > v;
    for(int i=0;i<n;i++)
    {
        job_no=i+1;
        cout<<"Start time of "<<i+1<<"th Job:";
        cin>>start_time;
        cout<<"End time of "<<i+1<<"th Job:";
        cin>>finish_time;
        v.push_back(make_pair(job_no,make_pair(start_time,finish_time)));
    }
    set<pair<int,pair<int,int>> > s=activitySelection(v);
    set<pair<int,pair<int,int>>>::iterator it;
    cout<<"Job Selected are: ";
    for(it=s.begin();it!=s.end();it++)
        cout<<(*it).first<<" ";
    return 0;
}
