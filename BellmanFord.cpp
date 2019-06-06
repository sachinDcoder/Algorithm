#include<iostream>
#include<climits>
#include<assert.h>
#include<tuple>
#include<set>
#include<vector>
#include<string.h>
#include<cstdio>
#include<stack>
using namespace std;
class Graph
{
    int noV;
    int noE;
    //pair<pair<int,int>,int> edge;
    set< pair<pair<int,int>,int> > edges;
    public:
        Graph(int v,int e)
        {
            noV=v;
            noE=e;
        }
        void addEdge(int src,int dest,int weg)
        {
            pair<pair<int,int>,int> p;
            p.first.first=src;
            p.first.second=dest;
            p.second=weg;
            edges.insert(p);
        }
        int getNoOfVertex()
        {
            return noV;
        }
        int getNoOfEdge()
        {
            return noE;
        }
        set< pair<pair<int,int>,int> > getEgdes()
        {
            return edges;
        }
};
void BellmanFord(Graph graph,int src)
{
    int V=graph.getNoOfVertex();
    int E=graph.getNoOfVertex();
    set< pair<pair<int,int>,int> > edges=graph.getEgdes();
    vector<int> dist(V);
    vector<int> parent(V);
    fill(dist.begin(),dist.end(),INT_MAX);
    dist[src]=0;
    parent[src]=-1;
    for(int i=0;i<V-1;i++)
    {
        set< pair<pair<int,int>,int> >::iterator it;
        for(it=edges.begin();it!=edges.end();it++)
        {
            int u=(*it).first.first;
            int v=(*it).first.second;
            int w=(*it).second;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
    bool isNegativeCycle=0;
    set< pair<pair<int,int>,int> >::iterator it;
    for(it=edges.begin();it!=edges.end();it++)
    {
        int u=(*it).first.first;
        int v=(*it).first.second;
        int w=(*it).second;
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
        {
            cout<<"Graph contains negative weight cycle"<<endl;
            isNegativeCycle=1;
            break;
        }
    }
    if(!isNegativeCycle)
    {
        /*for(int i=0;i<V;i++)
            cout<<i<<" "<<parent[i]<<" ";
        cout<<endl;*/
        cout<<"Shortest Distance from source to every other vertex as follow:"<<endl;
        printf("\n%4s %8s %5s\n","dest","distance","path");
        for(int i=0;i<V;i++)
        {
            printf("%4d %8d\t",i,dist[i]);
            int x=i;
            stack<int> stx;
            stx.push(i);
            while(x!=src)
            {
                x=parent[x];
                if(x==-1)
                {
                    stx.push(src);
                    break;
                }
                stx.push(x);
            }
            while(!stx.empty())
            {
                cout<<stx.top();
                stx.pop();
                if(stx.empty())
                    break;
                else
                    cout<<"->";
            }
            cout<<endl;
        }
    }
}
int main()
{
    int v,e,Vi,Vj,Wij;
    cout<<"Enter the number of edges and vertex as follow:"<<endl;
    cout<<"Edges:";
    cin>>e;
    cout<<"Vertex:";
    cin>>v;
    Graph graph(v,e);
    cout<<"Enter the information about all edges"<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<"From the vertex(Vi):";
        cin>>Vi;
        cout<<"To the vertex(Vj):";
        cin>>Vj;
        cout<<"Weight:";
        cin>>Wij;
        graph.addEdge(Vi,Vj,Wij);
    }
    BellmanFord(graph,0);
    return 0;
}
