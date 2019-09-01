#include <bits/stdc++.h>
#define vi vector<int>
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;
 
bool stat[32000];
int prime[10000], p = 1;
void sieve(){
    for (int i=3; i*i<32000 ; i+=2){
        if(!stat[i]){
            for(int j=i*i; j<=32000; j+=i+i)
                stat[j] = 1;
        }
    }
    prime[0] = 2;
    for (int i=3; i<32000; i+=2){
        if(!stat[i])
            prime[p++] = i;
    }
}
 
int countPrime(int fact, int k){
    int cnt{};
    while(fact){
        fact/=k;
        cnt += fact;
    }
    return cnt;
}
 
int countComp(int fact, int k){
    int ret = INT_MAX;
    for(int i=0; i<p && prime[i]*prime[i]<=k; i++){
        if(k%prime[i]==0){
            int cnt{};
            while(k%prime[i]==0){
                k/=prime[i];
                cnt++;
            }
            ret = min(ret, countPrime(fact, prime[i])/cnt);
        }
    }
    if(k>1){
        ret = min(ret, countPrime(fact, k));
    }
    return ret;
}
 
int main(){
 
    sieve();
    int t;
    sf(t);
    for (int tc=1; tc<=t; tc++){
        int n, k;
        sff(n, k);
        printf("Case %d: %d\n", tc, countComp(n, k));
    }
 
    return 0;
}
 