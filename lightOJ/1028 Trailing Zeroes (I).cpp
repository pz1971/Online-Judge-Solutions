#include <bits/stdc++.h>
#define vi vector<int>
#define sf(a) scanf("%lld", &a)
#define sff(a, b) scanf("%d%d", &a, &b)
typedef long long ll;
using namespace std;

bool stat[1000010];
int main()
{
    
    vi primes{2};
    for(int i=3; i*i<1000010; i+=2){
        if(!stat[i]){
            primes.push_back(i);
            for(int j=i*i; j<1000010; j+=i+i)
                stat[j] = 1;
        }
    }
    for(int i=primes.back()+2; i<1000010; i+=2)
        if(!stat[i])    primes.push_back(i);
 
    const int len = primes.size();
    int t;
    ll n;
    cin>> t;
    for(int tc=1; tc<=t; tc++){
        sf(n);
        int cnt{1};
        for(int i=0; i<len and primes[i]*primes[i] <= n; i++){
            int c{1};
            while(n%primes[i]==0){
                n /= primes[i];
                c++;
            }
            cnt *= c;
        }
        if(n > 1)
            cnt *= 2;
        printf("Case %d: %d\n", tc, cnt-1);
    }
 
    return 0;
}
 