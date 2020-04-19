#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

int CNT[30000005];

int main(){

    for(int d=1; d<30000000; d++){
        for(int k=2; k*d<=30000000; k++){
            if(d == ((k*d)^((k-1)*d))){
                CNT[ k*d ]++;
            }
        }
    }

    for(int i=1; i<30000005; i++){
        CNT[i] += CNT[i-1];
    }

    int t, n;
    sf(t);
    for(int tc=1; tc<=t; tc++){
        sf(n);
        printf("Case %d: %d\n", tc, CNT[n]);
    }

    return 0;
}
