#include<bits/stdc++.h>
using namespace std;
bool ara[1<<16];
int main()
{
    int n;
    cout<<"Enter range : ";
    cin>>n;

   /* for ( int i = 2; i <= n; i++){
        ara[i]=1;
    }*/
    for ( int i = 2; i*i <= n; i++){
        if(ara[i]==0){
            for ( int k=2; k*i <=n; k++){
                ara[k*i]=1;
            }
        }
    }
    for (int i = 2;i <= n; i++){
        if(ara[i]==0)cout<<i<<" ";
    }
}
