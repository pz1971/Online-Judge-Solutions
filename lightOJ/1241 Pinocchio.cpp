#include <bits/stdc++.h>
#define vi vector<int>
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

int main(){

    int t, n, x;
    sf(t);

    for(int tc=1; tc<=t; tc++){
        sf(n);
        int cnt{}, temp{2};
        
        while(n--){
            sf(x);
            cnt += ceil((x-temp)/5.0);
            temp = x;
        }
        
        printf("Case %d: %d\n", tc, cnt);
    }

    return 0;
}
