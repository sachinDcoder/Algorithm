#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
class Activity
{
    public:
        int job_no;
        int start_time;
        int finish_time;
        bool operator< (const Activity& e) const
        {
            return (job_no<e.job_no);
        }
};
bool sort_by(const Activity &a,const Activity &b)
{
    return (a.finish_time < b.finish_time);
}
set<Activity> activitySelection(Activity A[],int n)
{
    sort(A,A+n,sort_by);
    set<Activity> s;
    s.insert(A[0]);
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(A[i].start_time>=A[j].finish_time)
        {
            s.insert(A[i]);
            j=i;
        }
    }
    return s;
}
int main()
{
    int n;
    cout<<"Enter the number of Jobs: ";
    cin>>n;
    Activity A[n];
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        A[i].job_no=i+1;
        cout<<"Start time of "<<i+1<<"th Job:";
        cin>>A[i].start_time;
        cout<<"End time of "<<i+1<<"th Job:";
        cin>>A[i].finish_time;
    }
    set<Activity> s=activitySelection(A,n);
    set<Activity>::iterator it;
    cout<<endl<<"Job Selected are: ";
    for(it=s.begin();it!=s.end();it++)
        cout<<(*it).job_no<<" ";
    cout<<endl;
    return 0;
}
