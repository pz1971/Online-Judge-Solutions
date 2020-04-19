#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%lld %lld", &a, &b)
typedef long long ll;
using namespace std;

ll a, b;
int d, d2;
void binaryDigit(){
    d = d2 = 0;
    ll x = a;
    while(x){
        d++;    x /= 2;
    }
    x = b;
    while(x){
        d2++;    x /= 2;
    }
}

ll orO(){
    if(a==b)    return a;
    if(d<d2)    return (2LL << (d2-1)) - 1;
    ll x = a|b;
    for(int i=0; i<d; i++){
        if((x>>i)%2==0){
            ll y = a ^ (1LL<<i);
            if(y > b) break;
            x |= y;
        }
    }
    return x;
}

ll andO(){
    if(a==b)    return a;
    if(d<d2)    return 0;
    ll x = a&b;
    for(int i=0; i<d-1; i++){
        if((x>>i)%2==1){
            ll y = b ^ (1LL<<i);
            if(y < a) break;
            x &= y;
        }
    }
    return x;
}

int main(){

    int t;
    sf(t);
    for(int tc =1 ;tc<=t; tc++){
        sff(a, b);
        binaryDigit();
        printf("Case %d: %lld %lld\n", tc, orO(), andO());
    }

    return 0;
}
