#include<iostream>
using namespace std;
#include<climits>
#include<list>
#include<queue>
#define INF INT_MAX
class Graph
{
    private:
        int V;
        list<pair<int,int> > *AdjList;
    public:
        Graph(int no_of_vertices);
        void addEdge(int u,int v,int w);
        void Dijsktra(int s);
};
Graph::Graph(int no_of_vertices)
{
    V=no_of_vertices;
    AdjList=new list<pair<int,int> >[V];
}
void Graph::addEdge(int u,int v,int w)
{
    AdjList[u].push_back(make_pair(v,w));
    AdjList[v].push_back(make_pair(u,w));
}
void Graph::Dijsktra(int source)
{
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > pq;
    vector<int> dist(V,INF);
    pq.push(make_pair(0,source));
    dist[source]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator it;
        for(it=AdjList[u].begin();it!=AdjList[u].end();++it)
        {
            int v=(*it).first;
            int w=(*it).second;
            if(dist[v]>(dist[u]+w))
            {
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    cout<<"Shorted path"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
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
    g.Dijsktra(s);
    return 0;
}














