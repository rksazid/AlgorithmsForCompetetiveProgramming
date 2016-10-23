#include<bits/stdc++.h>
using namespace std;
#define Max_N 100
#define Max_W 1000

int weight[Max_N+1],cost[Max_N+1],dp[Max_N+1][Max_W+1],CAP,n;

int knapsack(int i, int w)
{
    if(i==n+1)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    int profit1=0,profit2=0;
    if(w+weight[i]<=CAP)
        profit1=cost[i]+knapsack(i+1,w+weight[i]);
    profit2=knapsack(i+1,w);
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<"Enter Item & capacity : ";
    cin>>n>>CAP;
    for(int i=1;i<=n;i++){
        cout<<"Weight "<<i<<": ";
        cin>>weight[i];
        cout<<"Cost "<<i<<": ";
        cin>>cost[i];
    }
    cout<<"Ans is : "<<knapsack(1,0);
    return 0;
}
