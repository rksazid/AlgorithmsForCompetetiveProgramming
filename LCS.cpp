#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
string s1,s2;
stack<char>st;

int main(){
    int m,n;
    memset(dp,0,sizeof dp);
    cin>>s1;
    cin>>s2;
    m = s2.size()+1;
    n = s1.size()+1;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i = n,j = m;
    while(i>0 && j>0){
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else if(dp[i-1][j] < dp[i][j-1]){
                j--;
            }
            else{
                    i--;
                    j--;
                    st.push(s1[i]);
            }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }

}
