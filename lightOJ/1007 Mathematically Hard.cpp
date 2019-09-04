#include <bits/stdc++.h>
#define vi vector<int>
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%lld%lld", &a, &b)
typedef long long ll;
using namespace std;

const int mx = 5000005;
unsigned long long phi[mx];
int mark[mx];

void seivePhi()
{
    for(int i=2; i<mx; i++) phi[i] = i;
    for(int i=2; i<mx; i++){
        if(!mark[i]){
            for(int j=i; j<mx; j+=i){
                mark[j] = i;
                phi[j] = phi[j]/i *(i-1);
            }
        }
    }
    for(int i=3; i<mx; i++){
        phi[i] *= phi[i];
        phi[i] += phi[i-1];
    }
}

int main()
{

    seivePhi();
    int t;
    ll a, b;
    sf(t);
    for(int tc=1; tc<=t; tc++){
        sff(a, b);
        printf("Case %d: %llu\n", tc, phi[b]-phi[a-1]);
    }

    return 0;
}
