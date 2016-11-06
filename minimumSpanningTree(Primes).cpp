#include<bits/stdc++.h>
using namespace std;

vector <int> G[100];
int cost[100][100];
int dis[100];
int parent[100];
bool visited[100];

struct data{
    int u,v,cost;
    data(int u,int v,int cost):u(u),v(v),cost(cost){}
    bool operator < (const data& p)const{
        return cost>p.cost;
    }
};

vector<data>M;

void mst(int src,int n){
    visited[src] = true;
    priority_queue<data>pQ;
    for(int i = 0;i<G[src].size();i++){
        pQ.push(data(src,G[src][i],cost[src][G[src][i]]));
    }
    while(M.size() < (n-1)){
        data node = pQ.top();
        pQ.pop();
        if(!visited[node.v]){
//            visited[node.u] = true;
            M.push_back(node);
            visited[node.v] = true;
            for(int i = 0; i<G[node.v].size() ;i++){
                int m = G[node.v][i];
                if(!visited[m]){
                    pQ.push(data(node.v,m,cost[node.v][m]));
                }
            }
        }
    }
}

int main(){
    int node,edge;
    cout<<"Enter number of node & Edge : ";
    cin>>node>>edge;
    cout<<"Enter Edges & cost :"<<endl;
    for(int i=0 ; i<edge ; i++){
        int u,v,cost_;
        cin>>u>>v>>cost_;
        G[u].push_back(v);
        G[v].push_back(u);
        cost[u][v] = cost_;
        cost[v][u] = cost_;
    }
    int src;
    cout<<"Enter Source node : ";
    cin>>src;
    mst(src,node);
    cout<<"MST IS : "<<endl;
    for(int i = 0;i<M.size();i++){
        cout<<M[i].u<<" "<<M[i].v<<endl;
    }
}
