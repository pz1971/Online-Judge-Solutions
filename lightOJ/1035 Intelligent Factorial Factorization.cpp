#include <bits/stdc++.h>
#define vi vector<int>
#define sf(a) scanf("%d", &a);
typedef long long ll;
using namespace std;

int cnt(int n, int i){
    int c{};
    while(n){
        n/=i;
        c += n;
    }
    return c;
}
int main()
{

    vector<bool> stat(51, 1);
    for(int i=3; i*i<101; i+=2){
        if(stat.at(i>>1)){
            for(int j=i*i; j<101; j+=i+i)
                stat.at(j>>1) = 0;
        }
    }
    vi primes;
    for(int i=3; i<101; i+=2){
        if(stat.at(i>>1))
            primes.push_back(i);
    }
    stat.clear();

    int n, t, tc{};
    sf(t);
    while(tc < t){
        sf(n);
        printf("Case %d: %d = 2 (%d)", ++tc, n, cnt(n, 2));
        for(auto i: primes){
            if(i>n) break;
            printf(" * %d (%d)", i, cnt(n, i));
        }
        printf("\n");
    }

    return 0;
}
