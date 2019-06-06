#include<iostream>
using namespace std;
#include<climits>
#include<list>
#include<queue>
#include<stack>
#define INF INT_MAX
class Graph
{
    private:
        int V;
        list<int> *AdjList;
    public:
        Graph(int no_of_vertices);
        void addEdge(int u,int v);
        void topoSort();
        void topoSortUtil(int vertex, vector<bool > &visited, stack<int > &s);
};

Graph::Graph(int no_of_vertices)
{
    V=no_of_vertices;
    AdjList=new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    AdjList[u].push_back(v);
}

void Graph::topoSortUtil(int vertex, vector<bool>& visited, stack<int>& s)
{
     list<int>::iterator it;
     visited[vertex]=true;
     for(it=AdjList[vertex].begin();it!=AdjList[vertex].end();it++)
     {
        if(!visited[*it])
            topoSortUtil(*it, visited, s);
     }
     s.push(vertex);
}

void Graph::topoSort()
{
    stack<int> s;
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++)
        if(visited[i]==false)
            topoSortUtil(i, visited, s);

    //cout<<s.size();
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    int v,s,d,w,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    Graph g(v);
    cout<<"Enter the number of edged: ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<endl;
        cout<<"Enter the vertex v1 of the edge: ";
        cin>>s;
        cout<<"Enter the vertex v2 of the edge: ";
        cin>>d;
        g.addEdge(s, d);
    }
    g.topoSort();
    return 0;
}


/*
6
6
5
2
5
0
4
0
4
1
2
3
3
1
*/









