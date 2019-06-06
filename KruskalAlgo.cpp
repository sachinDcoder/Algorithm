#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Graph
{
    private:
        int noV;
        int noE;
        vector<pair<int,pair<int,int>>> edgesSet;
    public:
        Graph(int V,int E)
        {
            noV=V;
            noE=E;
        }
        void addEdge(int u,int v,int w)
        {
            edgesSet.push_back(make_pair(w,make_pair(u,v)));
        }
        int getNoOfVertex(){return noV;}
        int getNoOfEdges(){return noE;}
        vector<pair<int,pair<int,int>>> getEdgesSet(){return edgesSet;}
};
class DisjointSets
{
    private:
        vector<int> parent;
        vector<int> rnk;
        int noElements;
    public:
        DisjointSets(int noE)
        {
            noElements=noE;
            parent.resize(noE+1);
            rnk.resize(noE+1);
            for(int i=0;i<=noE;i++)
            {
                parent[i]=i;
                rnk[i]=0;
            }
        }
        int findSet(int x)
        {
            if(parent[x]!=x)
                parent[x]=findSet(parent[x]);
            else
                return parent[x];
        }
        int mergeSet(int u,int v)
        {
            int x=findSet(u);
            int y=findSet(v);
            if(rnk[x]>rnk[y])
                parent[y]=x;
            else if(rnk[x]<=rnk[y])
                parent[x]=y;
            if(rnk[x]==rnk[y])
                rnk[y]++;
        }
};
set<pair<pair<int,int>,int>> kruskalAlgoMST(Graph g)
{
    vector<pair<int,pair<int,int>>> Edges=g.getEdgesSet();
    int V=g.getNoOfVertex();
    int E=g.getNoOfEdges();
    DisjointSets D(V);
    sort(Edges.begin(),Edges.end());
    vector<pair<int,pair<int,int>>>::iterator it;
    set<pair<pair<int,int>,int>> setMST;
    //int minmWegMST=0;
    for(it=Edges.begin();it!=Edges.end();it++)
    {
        //cout<<"**"<<endl;
        int u=(*it).second.first;
        int v=(*it).second.second;
        int w=(*it).first;
        //cout<<u<<" - "<<v<<" : "<<w<<endl;
        int setU=D.findSet(u);
        int setV=D.findSet(v);
        if(setU!=setV)
        {
            setMST.insert(make_pair(make_pair(u,v),w));
            //minmWegMST+=w;
            D.mergeSet(u,v);
        }
    }
    return setMST;
}
int main()
{
    int V,E;
    cout<<"Enter the no. of vertices:";
    cin>>V;
    cout<<"Enter the no. of edges:";
    cin>>E;
    Graph g(V,E);
    int u,v,w;
    cout<<"Enter edges and corresponding weight as follow:\n";
    for(int i=0;i<E;i++)
    {
        cout<<"v1 : ";
        cin>>u;
        cout<<"v2 : ";
        cin>>v;
        cout<<"weight : ";
        cin>>w;
        g.addEdge(u,v,w);
        cout<<endl;
    }
    set<pair<pair<int,int>,int>> setMST=kruskalAlgoMST(g);
    set<pair<pair<int,int>,int>>::iterator it;
    int minmWegMST=0;
    cout<<"Edges of the MST with correspond weight are given as : "<<endl;
    for(it=setMST.begin();it!=setMST.end();it++)
    {
        int u=(*it).first.first;
        int v=(*it).first.second;
        int w=(*it).second;
        minmWegMST+=w;
        cout<<u<<" - "<<v<<" : "<<w<<endl;
    }
    cout<<"Minimum weight : "<<minmWegMST<<endl;
    return 0;
}
