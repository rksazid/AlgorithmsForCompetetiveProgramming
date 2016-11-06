#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,ans = 0;
    cin>>t;
    while(t--){
        ans = 0;
        int n,cap,w = 0,I,np;
        int wt[100],val[100],p[100];
        int v[100][100];
        memset(v,0,sizeof v);
        cin>>n;
        for(int i= 1 ;i<=n;i++){
           cin>>val[i]>>wt[i];
        }
        cin>>np;
        for(int i = 1;i<=np;i++){
            cin>>p[i];
            w = max(w,p[i]);
        }
        for(int i = 1;  i < n+1;i++){
            for(int j = 1 ; j < w+1 ; j++){
                if(wt[i] > j){
                    v[i][j] = v[i-1][j];
                }
                else{
                    int x = j - wt[i];
                    v[i][j] = max(v[i-1][j],val[i]+v[i-1][x]);
                }
            }
        }
        for(int i = 1 ; i<=np;i++ ){
            int x = p[i];
            ans += v[n][x];
        }
        cout<<ans<<endl;
    }

}
