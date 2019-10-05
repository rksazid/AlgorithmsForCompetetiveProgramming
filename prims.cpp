#include<bits/stdc++.h>
using namespace std;
#define fi first;
#define se second;
typedef pair<int, int> pi;
int V,E;
int visited[1000000];

vector<pair<int,int>> ans;

void prims(vector<pair<int,int>> *graph)
{
int count=V-1;
int dist[V+1];

int parent[V+1];
for(int i=0;i<=V;i++)
{
dist[i]=INT_MAX;
parent[i]=0;
}
dist[1]=0;
priority_queue<pi, vector<pi>, greater<pi> > pq;
pq.push(make_pair(dist[1],1));

while(!pq.empty())
{
int u=pq.top().se;pq.pop();
if(visited[u])
continue;
ans.push_back(make_pair(u,parent[u]));visited[u]=1;

for(int v=0;v<graph[u].size();v++)
{
int tmp=graph[u][v].fi;
int wt=graph[u][v].se;
if(!visited[tmp])
{
if(dist[tmp] > wt)
{
dist[tmp]=wt;
parent[tmp]=u;
pq.push(make_pair(wt,tmp));

}
}
}
if(count--==0)
break;

}
for(int i=1;i<=V;i++)
cout<<dist[i]<<" ";
cout<<endl;
return;
}

int main()
{
int s,d,w;
cout<<"No. of vertices :";
cin>>V;
vector<pair<int,int>> graph[V+1];
cout<<"Edges :";
cin>>E;
for(int i=0;i<E;i++)
{
cin>>s>>d>>w;
graph[s].push_back(make_pair(d,w));
graph[d].push_back(make_pair(s,w));
}

prims(graph);

for(int i=0;i<ans.size();i++)
{
int s=ans[i].fi;
cout<<s<<"<->";
cout<<ans[i].se;
cout<<endl;
}

return 0;
}