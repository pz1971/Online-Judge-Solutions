#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

int phi[1000001];
void sievePHI(){
    for(int i=1; i<1000001; i++)    phi[i] = i;
    for(int i=2; i<1000001; i++){
        if(phi[i]==i){
            for(int j=i; j<1000001; j += i){
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main(){

    sievePHI();
    int n;
    while(sf(n)!=EOF && n!=0){
        if(n<1000001){
            printf("%d\n", phi[n]);
        }
        else{
            int x = n;
            if(n%2==0){
                while(n%2==0)
                    n /= 2;
                x -= x/ 2;
            }
            for(int i=3; i*i<=n; i+=2){
                if(n%i==0){
                    while(n%i==0)
                        n /= i;
                    x -= x/i;
                }
            }
            if(n>1) printf("%d\n", x - (x/n));
            else    printf("%d\n", x);
        }
    }

    return 0;
}
