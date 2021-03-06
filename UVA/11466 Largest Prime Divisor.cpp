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

int stat[1000000];
vector<ll> primes{2};

int main(){

    for(int i=3; i*i<1000000; i+=2){
        if(!stat[i]){
            primes.pb(i);
            for(int j=i*i; j<1000000; j+= i+i)
                stat[j] = 1;
        }
    }
    for(int i=primes.back(); i<1000000; i+=2){
        if(!stat[i])
            primes.pb(i);
    }

    ll n;
    while(scanf("%lld", &n)!= EOF && n){
        if(n<0) n = 0-n;
        if(n<4 || (n%2 && n<1000000 && !stat[n])){
            printf("-1\n");
            continue;
        }
        ll LPD = 1;
        int cnt = 0;
        for(auto i: primes){
            if(n==1 || i*i > n) break;
            if(n%i==0){
                LPD = i;
                cnt++;
                while(n%i==0){
                    n /= i;
                }
            }
        }
        for(ll i = primes.back()+2; i*i<=n; i+=2){
            if(n%i==0){
                LPD = i;
                cnt++;
                while(n%i==0){
                    n /= i;
                }
            }
        }
        if(n>1){
            LPD = n;
            cnt++;
        }
        if(cnt==1) LPD = -1;
        printf("%lld\n", LPD);
    }
    return 0;
}
