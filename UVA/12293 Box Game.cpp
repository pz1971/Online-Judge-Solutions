#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

    LL n;
    while(scanf("%lld", &n)!=EOF && n){
        LL x=1LL;
        while(x<n){
            x = (x*2) + 1;
        }
        puts(x!=n? "Alice" : "Bob");
    }

    return 0;
}
