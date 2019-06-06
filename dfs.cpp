#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Graph
{
    private:
        ll V;
        list<ll> *adj;
    public:
        void addEdge(ll u,ll v);
        Graph(ll v);
        void dfs(ll s);
        void dfsUtil(ll s,vector<bool> &isVisited);
        void bfs(ll s);
};
Graph::Graph(ll v)
{
    V=v;
    adj=new list<ll>[v];
}
void Graph::addEdge(ll u,ll v)
{
    adj[u].push_back(v);
}
void Graph::dfsUtil(ll v,vector<bool> &isVisited)
{
    isVisited[v]=true;
    cout<<v<<" ";
    list<ll>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(!isVisited[*it])
            dfsUtil(*it,isVisited);
    }
}
void Graph::dfs(ll s)
{
    vector<bool> v(V,false);
    //memset(arr,false,sizeof(bool)*V);
    dfsUtil(s,v);
}
void Graph::bfs(ll s)
{
    vector<bool> isVisited(V,false);
    isVisited[s]=true;
    queue<ll> q;
    q.push(s);
    while(!q.empty())
    {
        ll x=q.front();
        cout<<x<<" ";
        q.pop();
        list<ll>::iterator it;
        for(it=adj[x].begin();it!=adj[x].end();it++)
        {
            if(!isVisited[*it])
            {
                isVisited[*it]=true;
                q.push(*it);
            }
        }
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.dfs(2);
    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
}
