#include<iostream>
#include<cstdio>
using namespace std;
bool isSafe(const int n,bool **graph,const int v,int *color,const int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1 && c==color[i])
            return false;
    }
    return true;
}
bool graphColoring(const int n,bool **graph,int v,int *color)
{
    if(v>=n)
    {
        int maxm=0;
        printf("%s","vertex: ");
        for(int i=0;i<n;i++)
            printf("%4d",i);
        printf("\n%s","color: ");
        for(int i=0;i<n;i++)
        {
            printf("%4d",color[i]);
            if(maxm<color[i])
                maxm=color[i];
        }
        cout<<"\nChromatic No: "<<maxm<<endl;
        return true;
    }
    for(int i=1;i<=n;i++)
    {
        if(isSafe(n,graph,v,color,i))
        {
            color[v]=i;
            if(graphColoring(n,graph,v+1,color))
                return true;
            color[v]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the number of nodes in graph:";
    cin>>n;
    bool **graph;
    graph=new bool*[n];
    for(int i=0;i<n;i++)
        graph[i]=new bool[n];

    int *color;
    color=new int[n];
    cout<<"Enter 1 if there is node else 0:\n";
    for(int i=0;i<n;i++)
    {
        color[i]=0;
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    if(!graphColoring(n,graph,0,color))
        cout<<"No Solution"<<endl;
    return 0;
}
/*
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
*/
