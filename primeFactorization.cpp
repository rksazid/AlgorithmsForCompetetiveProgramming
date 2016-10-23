#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

map<ll,ll> m;
map<ll,ll>::iterator it;
void pFact(ll n){
    while(n%2==0){
        n/=2;
        m[2]++;
    }
    for(ll i=3 ; i*i<=n ;i = i+2){
        while(n%i==0){
            n/=i;
            m[i]++;
        }
    }
    if(n>0)m[n]++;
}

void print(){
    it = m.begin();
    while(it != m.end()){
        printf("%lld POW %lld\n",it->first,it->second);
        it++;
    }
}

int main(){
    ll n_;
    while(true){
     scanf("%lld",&n_);
     pFact(n_);
     print();
     m.clear();
    }
}
