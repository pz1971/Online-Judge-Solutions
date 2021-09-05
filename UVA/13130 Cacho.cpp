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

int main(){

    int t, a, b;
    sf(t);
    while(t--){
        sf(b);
        bool y = true;
        for(int i=1; i<5; i++){
            sf(a);
            if(a!=b+1)  y = false;
            b = a;
        }
        printf( y ? "Y\n" : "N\n");
    }

    return 0;
}
