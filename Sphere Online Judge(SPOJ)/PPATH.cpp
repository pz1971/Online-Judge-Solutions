#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
int stat[10000];
int vis[10000];
VI primes;
VI adj[10000];
 
int bfs(int s, int t){
    if(s==t)    return 0;
    memset(vis, 0, sizeof vis);
    queue<int>  q;
    q.push(s);
    vis[s] = 1;
    
    while(!q.empty()){
        int temp = q.front(); q.pop();
        for(int i=0; i<adj[temp].size(); i++){
            if(!vis[adj[temp][i]]){
                vis[adj[temp][i]] = vis[temp] + 1;
                q.push(adj[temp][i]);
                if(vis[t])
                    return vis[t] - 1;
            }
        }
    }
 
    return -1;
}
 
bool ifAdj(int a, int b){
    int diff = 0;
    while(a || b){
        if((a%10) != (b%10) && ++diff > 1)
            return false;
        a /= 10;
        b /= 10;
    }
    return true;
}
 
int main(){
 
    for(int i=3; i*i<10000; i+=2){
        if(!stat[i]){
            for(int j=i*i; j<10000; j+=i+i)
                stat[j] = 1;
        }
    }
    for(int i=1001; i<10000; i+=2)
        if(!stat[i])
            primes.push_back(i);
    int sz = primes.size();
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            if(ifAdj(primes[i], primes[j])){
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
    }
    
    int tc;
    int s, t, ans;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &s, &t);
        ans = bfs(s, t);
        printf(ans == -1 ? "Impossible\n" : "%d\n", ans);
    }
 
    return 0;
}
