#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll M;

ll bigMod(ll N,ll P){
    if(P == 0) return 1;
    if(P&1 == 0){
        ll ret = bigMod(N,P/2);
        return ((ret%M)*(ret%M))%M;
    }
    else{
        return ((N%M)*bigMod(N,P-1)%M)%M;
    }
}

int main(){
    ll N,P;
    cin>>N>>P>>M;
    cout<<bigMod(2,P);
}
