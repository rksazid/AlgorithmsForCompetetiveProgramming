#include<bits/stdc++.h>
using namespace std;
int coin[] = {0,1,5,7,4};
bool possible[100000]={false};
int main(){
    int n,k = 5;
    cin>>n;
    possible[0]=1;
    for(int i= 1;i<=n;i++)
        for(int j=1;j<=k;j++)
            if(i>=coin[j])
                possible[i]|= possible[i-coin[j]];
    if(possible[n])cout<<"YES";
    else cout<<"NO";
}
