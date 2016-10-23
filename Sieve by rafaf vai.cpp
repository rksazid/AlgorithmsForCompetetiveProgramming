#include<bits/stdc++.h>
using namespace std;
#define N 10000005
typedef vector<int> vi;
vi prime;
bool isPrime[N];
int nextPrime( int i) { while( !isPrime[++i]); return i;}
void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    int i,j;
    isPrime[0] = isPrime[1] = false;
    for(i=4; i<=N; i+=2) isPrime[i] = false;

    int sq = (int) sqrt(N);

    for(i=3; i<=sq; i=nextPrime(i))
    {
        for(j=i*i; j<=N; j+=i) isPrime[j] = false;
    }
    //for(i=2; i<=N; i++) if( isPrime[i]) prime.push_back(i);
}

int main(){
    sieve();
    //for(int i=0;i<prime.size();i++)cout<<prime[i]<<" ";
    cout<<isPrime[10000001];
}
