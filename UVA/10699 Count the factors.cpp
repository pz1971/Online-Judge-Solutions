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

int stat[1000020];
vi primes{2};

int main(){

    for(int i=3; i*i<1000020; i+=2){
        if(!stat[i]){
            primes.pb(i);
            for(int j=i*i; j<1000020; j+= i+i)
                stat[j] = 1;
        }
    }
    for(int i=primes.back(); i<1000020; i+=2)
        if(!stat[i])    primes.pb(i);

    int n;
    while(sf(n)!=EOF && n){
        printf("%d : ", n);
        int cnt = 0;
        for(auto i: primes){
            if(i*i > n) break;
            if(n%i==0){
                cnt++;
                while(n%i==0)   n/= i;
            }
        }
        if(n>1) cnt++;
        printf("%d\n", cnt);
    }

    return 0;
}
