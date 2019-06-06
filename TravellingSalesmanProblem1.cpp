#include<bits/stdc++.h>
using namespace std;
#define MAX 100
vector<set<int> > allSets(int a[MAX],int n)
{
    vector<set<int> > A;
    int pset_size=pow(2,n);
    for(int counter=0;counter<pset_size;counter++)
    {
        set<int> tmp;
        for(int j=0;j<n;j++)
        {
            if(counter & (1<<j))
            {
                tmp.insert(a[j]);
            }
        }
        A.push_back(tmp);
    }
    return A;
}
bool sort_by(set<int>& a,set<int>& b)
{
    return a.size() < b.size();
}
void tsp(int graph[MAX][MAX],int n)
{
    int a[MAX];
    for(int i=0;i<n-1;i++)
        a[i]=i+1;
    vector<set<int> > A=allSets(a,n-1);
    vector<set<int> >::iterator Ait;
    map<pair<int,set<int>>,int> D;
    map<pair<int,set<int>>,int> P;
    map<pair<int,set<int>>,int>::iterator Mit;
    sort(A.begin(),A.end(),sort_by);
    for(int i=1;i<n;i++)
    {
        pair<int,set<int> > p;
        p.first=i;
        p.second={};
        int value=graph[0][i];
        D[p]=value;
        P[p]=0;
    }
    int c=1,i,tparent;
    for(c=1;c<n-1;c++)
    {
        for(i=1;i<n;i++)
        {
            for(Ait=A.begin();Ait!=A.end();Ait++)
            {
                if((*Ait).size()==c)
                {
                    int minm=INT_MAX;
                    set<int> temp=(*Ait);
                    set<int>::iterator Sit,Xit;
                    Xit=(*Ait).find(i);
                    if(Xit!=(*Ait).end())
                        continue;
                    for(Sit=(*Ait).begin();Sit!=(*Ait).end();Sit++)
                    {
                        pair<int,set<int> > p;
                        p.first=(*Sit);
                        temp=(*Ait);
                        temp.erase(*Sit);
                        p.second=temp;
                        int x=graph[(*Sit)][i]+D[p];
                        if(minm>x)
                        {
                            minm=x;
                            tparent=(*Sit);
                        }
                    }
                    pair<int,set<int> > p;
                    p.first=i;
                    p.second=(*Ait);
                    temp=(*Ait);
                    D[p]=minm;
                    P[p]=tparent;
                }
            }
        }
    }
    pair<int,set<int> > finalp;
    for(Ait=A.begin();Ait!=A.end();Ait++)
    {
        if((*Ait).size()==c)
        {
            int minm=INT_MAX;
            set<int> temp=(*Ait);
            set<int>::iterator Sit,Xit;
            Xit=(*Ait).find(0);
            if(Xit!=(*Ait).end())
                continue;
            for(Sit=(*Ait).begin();Sit!=(*Ait).end();Sit++)
            {
                pair<int,set<int> > p;
                p.first=(*Sit);
                temp=(*Ait);
                temp.erase(*Sit);
                p.second=temp;
                int x=graph[(*Sit)][0]+D[p];
                if(minm>x)
                {
                    minm=x;
                    tparent=(*Sit);
                }
            }
            pair<int,set<int> > p;
            p.first=0;
            p.second=(*Ait);
            temp=(*Ait);
            finalp=p;
            D[p]=minm;
            P[p]=tparent;
        }
    }
    cout<<"Tsp solution: "<<D[finalp]<<endl;
    set<int> tset=finalp.second,es;
    cout<<0<<"->";
    while(finalp.second!=es)
    {
        int x=P[finalp];
        finalp.first=x;
        finalp.second.erase(x);
        cout<<x<<"->";
    }
    cout<<0<<endl;
}
int main()
{
    int n,i,j,k;
    cout<<"Enter the no. of vertex:";
    cin>>n;
    cout<<"Enter the graph:"<<endl;
    int graph[MAX][MAX];
    memset(graph,0,n*n*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    tsp(graph,n);
    return 0;
}
/*0 1 15 6
2 0 7 3
9 6 0 12
10 4 8 0
Tsp solution: 21
0->2->3->1->0*/

/*0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Tsp solution: 80
0->1->3->2->0*/
