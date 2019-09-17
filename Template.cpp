/**========================================================**/
/**  In the name of Allah , most Gracious , most Merciful  **/
/**========================================================**/

#include<bits/stdc++.h>
#include<iostream>
#include<map>

/** ===================== <Short-Cut> ===================== **/

#define ll            long long int
#define db            cout<<"Allahu Akbar"<<endl
#define pb(a)         push_back(a)
#define sf(t)         scanf("%d",&t)
#define sff(a,b)      scanf("%d %d",&a,&b)
#define sfff(a,b,c)   scanf("%d %d %d",&a,&b,&c)
#define sfll(a)       scanf("%lld",&a)
#define pf            printf
#define sc            scanf
#define uu            first
#define vv            second
#define MOD           1000000007
#define CAS           int t;sf(t)
#define Cloop         for(int M = 1;M<=t;M++)
#define Cprint        pf("Case %d: ",M)
#define all(a)        a.begin(),a.end()
#define ms(a,b)       memset(a, b, sizeof(a))
#define REP(O,a,n)    for(int O = a ; O<n ; O++)
#define CIN           ios_base::sync_with_stdio(0); cin.tie(0)
#define pi            2*acos(0.0)
#define insin(a,b)    asin(b/(double)a)
#define intan(a,b)    atan(b/(double)a)
#define Mx            1000000005
#define Ni 1000005

using namespace std;

/** ==================== <Functions> ==================== **/

ll POW_(ll n,ll p);
ll noOfDivisor(ll n);
ll baseChange(ll n,ll b);
ll largestPowerOfAPrimeInFactorial(ll n,ll p);

/** ==================== <Main Code> ==================== **/

int main(){
    //#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //#endif
    return 0;
}

/** ==================== <End of Main> ==================== **/


/** ====================== <Functions> ======================== **/

ll POW_(ll n,ll p){
    ll tmp = n;
    REP(i,0,p-1){
        tmp*=n;
    }
    return tmp;
}

/** ================= <Number Of Divisor> =============== **/

ll noOfDivisor(ll n){
    ll noOfDiv=1,p=0;
    while(n%2==0){
        n/=2;
        p++;
    }
    noOfDiv*=(p+1);
    for(ll i=3 ; i*i<=n ;i = i+2){
        p=0;
        while(n%i==0){
            n/=i;
            p++;
        }
        noOfDiv*=(p+1);
    }
    if(n>1)noOfDiv*=2;
    return noOfDiv;
}

/** ========== <Convert into different base> ========== **/

ll baseChange(ll n,ll b){
    ll tmp = 0,x,i = 1;
    while(n){
        x = n%b;
        n/=2;
        tmp+=x*i;
        i*=10;
    }
    return tmp;
}

/** ========== <Largest power of a prime in factorial> ========== **/

ll largestPowerOfAPrimeInFactorial(ll n,ll p){
    ll tmp = p;
    ll ans = 0;
  while (tmp <= n) {
    ans += n / tmp;
    tmp *= p;
  }
  return ans;
}

/** ==================== <End of Functions> ==================== **/
