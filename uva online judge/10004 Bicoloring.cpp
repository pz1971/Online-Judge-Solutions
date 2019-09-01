#include<bits/stdc++.h>
#define vi vector<short int>
#define pb push_back
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sf(a) scanf("%hd", &a)
#define sff(a, b) scanf("%hd %hd", &a, &b)
typedef long long ll;
using namespace std;

int main(){

    short int n, l;
    while(sf(n)!=EOF && n){
        vi ar[n];
        short int a, b;
        sf(l);
        while(l--){
            sff(a, b);
            ar[a].pb(b);
            ar[b].pb(a);
        }

        queue<short int> q;
        q.push(0);
        bool bc = true;
        vi stat(n);
        stat[0] = 1;

        while(!q.empty() && bc){
            int t = q.front();
            q.pop();
            for(int i=0; i<ar[t].size(); i++){
                if(stat[ar[t][i]]==0){
                    q.push(ar[t][i]);
                    stat[ar[t][i]] = 0 - stat[t];
                }
                else if(stat[ar[t][i]]==stat[t]){
                    bc = false;
                    break;
                }
            }
        }

        printf(bc ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    }

    return 0;
}
