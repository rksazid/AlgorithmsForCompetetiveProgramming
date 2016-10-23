#include<bits/stdc++.h>
#define mx 100002
typedef long long int ll;
using namespace std;

vector <ll> g[mx],cost_[mx];
int dis[mx];
ll parent[mx];

struct node{
    int city;
    int cost;
    node(int a,int b){
        city = a;
        cost = b;
    }
    bool operator<(const node& n)const{
        return cost>n.cost;
    }
};


int dijkstra(int src,int des){
    memset(dis,63,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    priority_queue<node> q;
    q.push(node(1,0));
    dis[src] = 0;
    while(!q.empty()){
        node t = q.top();
        q.pop();
        ll u =  t.city;
        if(u == des)
            return dis[des];
        for(int i = 0; i<(int)g[u].size();i++){
            ll v = g[u][i];
            if(cost_[u][i]+dis[u]<dis[v]){
                dis[v] = cost_[u][i]|+dis[u];
                q.push(node(v,dis[v]));
                parent[v] = u;
            }
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll p,q,r;
        cin>>p>>q>>r;
        g[p].push_back(q);
        g[q].push_back(p);
        cost_[p].push_back(r);
        cost_[q].push_back(r);
    }
    ll x = dijkstra(1,n);
    cout<<endl<<x;
}
