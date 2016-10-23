#include<bits/stdc++.h>
using namespace std;
#define MAX 9

int sum[4*MAX];
int num[9] = {0,1,2,3,4,5,6,7,8};
void creat(int idx,int L,int R){
    if(L == R){
        sum[idx] = num[L];
    cout<<sum[idx]<<endl;
        return;
    }
    int mid = (L+R)>>1;
    creat(idx<<1,L,mid);
    creat((idx<<1)+1,mid+1,R);
    sum[idx] = sum[idx*2]+sum[(idx*2)+1];
    cout<<sum[idx]<<endl;
}

int Query(int idx,int L,int R,int l,int r){
    if( r<L || R<l )return 0;
    if( l<=L && R<=r )return sum[idx];
    int mid = (L+R)>>1;
    return Query(idx<<1,L,mid,l,r)+Query((idx<<1)+1,mid+1,R,l,r);
}

int main(){
    creat(1,1,8);
    cout<<Query(1,1,8,1,8)<<endl;
}
