#include<bits/stdc++.h>
#define inf 1000000

using namespace std;

vector<int> v1,v2,cost;
vector<int>path;

int main()

{
    int c,n,m,a,b,w,i,j;
    int dis[1004];
    int parent[1004];

    for(i=0; i<1004; i++) dis[i]=inf;


    cout<<"Enter node and edge number : ";
    cin>>n>>m;

    cout<<"Enter edges and costs :"<<endl;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>w;

        v1.push_back(a);
        v2.push_back(b);
        cost.push_back(w);
    }

    int source ,destination;
    cout<<"Enter source and destination node :";
    cin>>source>>destination;

    dis[source]=0;
    parent[source]=-1;

    int p,k=1;
    int u,v;

    for(i=0; i<n; i++)
    {
        p=0;
        for(j=0; j<m; j++)
        {
            u=v1[j];
            v=v2[j];
            if(dis[u]+cost[j]<dis[v])
            {
                dis[v]=dis[u]+cost[j];
                parent[v]=u;
                p=1;

                if(i==n-1) k=0;
            }
        }
        if(p==0) break;
    }

    if(k==0)
    {
        cout<<endl<<"There is negative cycle"<<endl<<"So we cannot determine shortest path"<<endl<<endl;

        return 0;
    }
    else cout<<"There is no negative cycle"<<endl<<endl;

    path.push_back(destination);

    int kundu=parent[destination];

    while(1)
    {
        if(kundu==-1) break;

        else
        {
            path.push_back(kundu);

            kundu=parent[kundu];
        }
    }

    reverse(path.begin(),path.end());

    cout<<"minimum cost between source and destination is :"<<dis[destination]<<endl;


    cout<<endl<<"Shortest path : " ;

    for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";

    cout<<endl;
}
