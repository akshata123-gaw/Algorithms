#include<bits/stdc++.h>
using namespace std;

struct node
{
  int u;
  int v;
  int wt;
  
  node(int first, int second, int weight)
  {
    u=first;
    v=second;
    wt=weight;
  }
};

int main()
{
  int N, m;
  cin>>N>>m;
  vector<node> edges;
  for(int i=0; i<m;i++)
  {
    int u, v, wt;
    cin>>u>>v>>wt;
    edges.push_back(node(u, v, wt));
  }

  int src;
  cin>>src;

  int inf=10000000;
  vector<int> dist(N+1, inf);


  dist[src]=0;

  for(int i=1; i<N;i++)
  {
    for(auto it:edges)
    {
      if(dist[it.u]+it.wt < dist[it.v])
      {
        dist[it.v]=dist[it.u]+it.wt;
      }
    }
  }

  int flag=0;
  for(auto it: edges)
  {
    if(dist[it.u]+it.wt < dist[it.v])
    {
      cout<<"Negative Cycle";
      flag=1;
    }
  }

  if(!flag)
  {
    for(int i=0; i<N; i++)
    {
      cout<<i<<" "<<dist[i]<<endl;
    }
  }

  return 0;
}