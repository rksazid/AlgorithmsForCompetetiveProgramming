#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nways[9]={0};
    int coins[5]={2,4};
    int cent,total;
    nways[0]=1;
    for(int i=0;i<2;i++){
        for(int j=coins[i],k=0;j<=8;j++,k++){
            nways[j]+=nways[k];
        }
    }
    for(int i=0;i<=8;i++)cout<<nways[i]<<" ";
    return 0;
}
