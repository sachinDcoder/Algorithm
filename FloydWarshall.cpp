#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100
#include<climits>
#include<stack>
#define INF INT_MAX
void FloydWarshall(int dist[MAX][MAX],int path[MAX][MAX],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(dist[i][j]<=1000 && i!=j)
                path[i][j]=i;
            else
                path[i][j]=-1;
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(dist[i][i]<0)
        {
            cout<<"There is negative weight cycle in the graph"<<endl;
            return;
        }
    }
    cout<<"Distance matrix from floyd Warshall(shortest path from each vertex to every other vertex):"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%8d ",dist[i][j]);
        cout<<endl;
    }
    cout<<"Path matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%8d ",path[i][j]);
        cout<<endl;
    }
}
void printPath(int path[MAX][MAX],int dist[MAX][MAX],int s,int d)
{
    stack<int> st;
    int x=d;
    st.push(d);
    do
    {
        x=path[s][x];
        st.push(x);
    }while(x!=s);
    while(1)
    {
        x=st.top();
        st.pop();
        cout<<x;
        if(st.empty())
            break;
        else
            cout<<"--("<<dist[x][st.top()]<<")-->";
    }
    cout<<endl;
}
int main()
{
    int dist[MAX][MAX],i,j,k,n,x,s,d;
    int path[MAX][MAX];
    cout<<"Enter the size of matrix:";
    cin>>n;
    cout<<"Enter the distance matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>x;
            dist[i][j]=x;
        }
    }
    FloydWarshall(dist,path,n);
    cout<<"Enter source and distinction to know the path:"<<endl;
    cin>>s>>d;
    printPath(path,dist,s,d);
    return 0;
}
