#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define clr(a) memset(a, 0, sizeof a)
#define ALL(a) a.begin(), a.end()
#define sf(a) scanf("%lld", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

ll power(ll b, int p){
    ll ret = 1;
    while(p--) ret *= b;
    return ret;
}

int totalDigits(ll n){
    int d = 0;

    int p=0;
    while(n>0){
        n -= 9*power(10, p);
        d++;
        if(n<=0)    break;
        n -= 9*power(10, p);
        d++;
        p++;
    }

    return d;
}

void deletion(ll &n, int d){
    int p = 0;
    while(1){
        if(!d) break;
        n -= 9*power(10, p);       d--;
        if(!d)  break;
        n -= 9*power(10, p);  p++; d--;
    }
}

int main(){

    ll n;
    while(sf(n)!=EOF && n){
        int td = totalDigits(n), d;
        deletion(n, td-1);
        n--;
        if(td%2==0) d = td/2;
        else        d = (td/2)+1;
        int ar[d];
        for(int i=0; i<d; i++){
            ar[i] = n%10;   n/=10;
        }
        ar[d-1]++;
        int s;
        td%2==0 ? s=0 : s=1;
        for(int i=d-1; i>=s; i--)
            printf("%d", ar[i]);
        for(int i=0; i<d; i++)
            printf("%d", ar[i]);
        printf("\n");
    }

    return 0;
}
