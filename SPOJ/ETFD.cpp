#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define clr(a) memset(a, 0, sizeof a)
#define ALL(a) a.begin(), a.end()
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;
 
int phi[1000005];
void sievePhi(){
    for(int i=0; i<1000005; i++)
        phi[i] = i;
    for(int i=2; i<1000005; i++){
        if(phi[i]!=i)   continue;
        for(int j=i; j<1000005; j+=i)
            phi[j] = phi[j]/i*(i-1);
    }
}
int depth[1000005];
vi Ks[21];
void calcDepth(){
    depth[1] = 0;
    Ks[0].pb(1);
    for(int i=2; i<1000005; i++){
        depth[i] = depth[phi[i]] + 1;
        if(depth[i]<21)
            Ks[depth[i]].pb(i);
    }
}
 
int main(){
 
    fastIO;
    sievePhi(); calcDepth();
    int t, m, n, k;
    cin>> t;
    while(t--){
        cin>> m>> n>> k;
        int cnt = 0;
        for(int i: Ks[k]){
            if(i>n) break;
            if(i<m) continue;
            cnt++;
        }
        cout<< cnt<< endl;
    }
 
    return 0;
}
 