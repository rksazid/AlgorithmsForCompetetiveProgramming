#include<bits/stdc++.h>
#include<bitset>
#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++)
using namespace std;
long long _sieve_size;
bitset <10000010> bs;
vector <int> primes;

void sieve(long long upperbound){
    _sieve_size+upperbound + 1;
    bs.reset();
    bs.flip();
    bs.set(0,false);
    bs.set(1,false);
    for( long long i=2;i<=_sieve_size; i++)if(bs.test((size_t)i)){
        for(long long j=i*i; j<=_sieve_size; j+=i)bs.set((size_t)j,false);
        primes.push_back((int)i);
    }
}

bool isPrime(long long N){
  if(N<_sieve_size)return bs.test(N);
    REP (i,0,primes.size()-1)if(N % primes[i]==0)return false;
    return true;
}
int main()
{
    sieve(10000000);
    printf("%d\n", isPrime(4));
}
