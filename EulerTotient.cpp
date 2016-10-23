#include<bits/stdc++.h>
using namespace std;
int phi[1000006],mark[1000006];
int phii[10005];
int n=10005;
void sievePhi(){
    int i,j;
    for(i=1;i<=n;i++)phi[i] = i;
    phi[1] = 1;
    mark[1] = 1;

    for(i = 2;i<=n;i+=2){
        if(i!=2)mark[i] = 1;
        phi[i] = phi[i]/2;
    }

    for(i = 3;i<=n;i+=2){
        if(!mark[i]){
            phi[i] = phi[i] - 1;
            for(j = 2*i;j<=n;j+=i){
                mark[j] = 1;
                phi[j] = phi[j] /i *(i-1);
            }
        }
    }
}
void cum(){
    phii[1]= 1;
    for(int i=2;i<10005;i++)phii[i] = phii[i-1]+phi[i];
}
int main(){
    int t;
    cin>>t;
    int nn;
    sievePhi();
    cum();
    while(t--){
        cin>>nn;
//    int sum=0;
//    for(int i = 1;i<=nn;i++){
//        sum+=phi[i];
//    }
//    cout<<sum+1;
        cout<<ceil(pow((phi[n]+1),nn)/sqrt(5))<<endl;
    }
}
