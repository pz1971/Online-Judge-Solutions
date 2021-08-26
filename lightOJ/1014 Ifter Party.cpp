#include <bits/stdc++.h>
#define vi vector<ll>
typedef long long ll;
using namespace std;

void scanf(ll &n){
    n = 0;
    char ch;
    for(ch = getchar(); ch>='0' && ch<='9'; ch = getchar())
        n = n*10 + (ch-'0');
}

int main()
{

    ll t, l, p, tc{};
    scanf(t);
    
    for(ll tc=1; tc<=t; tc++){
        scanf(p); scanf(l);
        vi ar, ar2;
        
        printf("Case %d:", tc);
        p -= l;
        
        if(p <= l)
            printf(" impossible\n");
        else{
            ll i;
            for(i=1; i*i<p; i++){
                if(p%i==0){
                    if(i>l)
                        ar.push_back(i);
                    if((p/i) > l)
                        ar2.push_back(p/i);
                }
            }
            
            if(i*i==p && i>l) ar.push_back(i);
            
            for(i=0; i<ar.size(); i++)
                printf(" %d", ar.at(i));
            
            for(i=ar2.size()-1; i>=0; i--)
                printf(" %d", ar2.at(i));
            printf("\n");
        }
    }
    
    return 0;
}