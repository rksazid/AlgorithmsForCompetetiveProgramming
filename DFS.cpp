#include<bits/stdc++.h>
using namespace std;

vector <int> v[100];
bool visited[100];

void DFS(int u){
     visited[u]=1;
     cout<<u<<" ";
     for(int i=0 ; i<v[u].size() ; i++){
          int x = v[u][i];
          if(!visited[x])
               DFS(x);
     }
}

int main()
{
     int node,edge;
     cin>>node>>edge;
     for(int i=0 ; i<edge ; i++){
          int a,b;
          cin>>a>>b;
          v[a].push_back(b);
          v[b].push_back(a);
     }
     int src;
     cin>>src;
     DFS(src);
     return 0;
}

/**
7 8
1 2
1 3
3 7
2 7
3 4
4 5
5 6
7 6
**/
