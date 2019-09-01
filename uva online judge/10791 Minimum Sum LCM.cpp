#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define clr(a) memset(a, 0, sizeof a)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

int stat[25000];
vector<ll> primes{2};

ll power(ll a, int p){
    ll ret = a;
    while(--p)
        ret *= a;
    return ret;
}

int main(){

    for(int i=3; i*i<50000; i+=2){
        if(!stat[i>>1]){
            primes.pb(i);
            for(int j=i*i; j<50000; j+= i+i)
                stat[j>>1] = 1;
        }
    }
    for(int i=primes.back(); i<50000; i+=2){
        if(!stat[i>>1])
            primes.pb(i);
    }

    ll n;
    int tc = 0;
    while(scanf("%lld", &n)!= EOF && n){
        if(n<4 || ( n%2 && n<50000 && !stat[n>>1] ) ){
            printf("Case %d: %lld\n", ++tc, n+1);
            continue;
        }
        bool isPrime = true;
        ll ans = 0;
        int p = 0;

        for(ll i: primes){
            if(i*i>n)   break;
            if(n%i!=0)  continue;

            isPrime = false;
            p++;
            int cnt = 0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            ans += power(i, cnt);
        }

        if(isPrime) ans = n+1;
        else if(n!=1){
            p++;
            ans += n;
        }
        if(p==1)    ans++;

        printf("Case %d: %lld\n", ++tc, ans);
    }

    return 0;
}
