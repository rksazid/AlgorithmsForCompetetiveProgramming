#include<bits/stdc++.h>
using namespace std;

vector < int > G[100];
bool visited[100];
int parent[100];
int dis[100];
int edge,node;

void path_print(int u){
    if(u==-1)return;
    path_print(parent[u]);
    printf("%d ",u);
}

void BFS(int src){
    queue  <int> Q;
    Q.push(src);
    dis[src] = 0;
    parent[src] = -1;
    memset(visited,0,sizeof visited);
    visited[src] = 1;
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int i = 0 ; i<G[u].size() ; i++){
            int v = G[u][i];
            if(!visited[v]){
                dis[v] = dis[u]+1;
                parent[v] = u;
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
//    for (int i=1 ; i<=node ; i++){
//        printf("%d to %d distance = %d\n",src,i,dis[i]);
//        printf("Path = ");
//        if (visited[i])
//            path_print(i);
//        printf("\n");
//    }
}
int main(){
     cin>>node>>edge;
     for(int i=0 ; i<edge ; i++){
          int a,b;
          cin>>a>>b;
          G[a].push_back(b);
          G[b].push_back(a);
     }
     int src;
     cin>>src;
     BFS(src);
     int k;
     cin>>k;
     path_print(k);
     return 0;
}
