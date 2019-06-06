#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<climits>
#define INF INT_MAX
using namespace std;
class Graph
{
    private:
        int V;
        list<pair<int,int> > *AdjList;
    public:
        Graph(int v)
        {
            V=v;
            AdjList=new list<pair<int,int> >[V];
        }
        void addEdge(int u,int v,int w)
        {
            AdjList[u].push_back(make_pair(v,w));
            AdjList[v].push_back(make_pair(u,w));
        }
        int getNoOfVertex()
        {
            return V;
        }
        list<pair<int,int> >* getAdjacencyList()
        {
            return AdjList;
        }
};
void primMST(Graph graph)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    int noV=graph.getNoOfVertex();
    map<int,int> m;
    list<pair<int,int> > *AdjList=graph.getAdjacencyList();
    vector<bool> inMST(noV,false);
    vector<int> key(noV,INF);
    vector<int> parent(noV,-1);
    int totalWegOfMST=0;
    pq.push(make_pair(0,0));
    while(!pq.empty())
    {
        int u=pq.top().second;
        int minW=pq.top().first;
        pq.pop();
        totalWegOfMST+=minW;
        inMST[u]=true;
        list<pair<int,int> >::iterator lit;
        for(lit=AdjList[u].begin();lit!=AdjList[u].end();lit++)
        {
            int v=(*lit).first;
            int w=(*lit).second;
            if(inMST[v]==false && key[v]>w)
            {
                key[v]=w;
                pq.push(make_pair(w,v));
                parent[v]=u;
            }
        }
    }
    for(int i=1;i<noV;i++)
    {
        cout<<parent[i]<<" -- "<<i<<endl;
    }
}
int main()
{
    int v,s,d,w,e;
    cout<<"Enter the number of vertices:";
    cin>>v;
    Graph g(v);
    cout<<"Enter the number of edged:";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<endl;
        cout<<"Enter the vertex v1 of the edge:";
        cin>>s;
        cout<<"Enter the vertex v2 of the edge:";
        cin>>d;
        cout<<"Enter the weight of the edge:";
        cin>>w;
        g.addEdge(s, d, w);
    }
    cout<<"Enter the source";
    cin>>s;
    primMST(g);
    return 0;
}
