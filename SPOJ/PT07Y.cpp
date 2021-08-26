#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
VI g[10005];
int vis[10005];
 
bool dfs(int root, int val){
	vis[root] = val + 1;
 
	bool ret = true;
 
	for(auto i : g[root]){
		if(vis[i] == val)
			continue;
		else if(vis[i])
			return false;
		ret &= dfs(i, val + 1);
		if(!ret)
			break;
	}
 
	return ret;
}
 
int main(){
 
	int n, m, u, v;
	scanf("%d %d", &n, &m);
 
	while(m--){
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	bool root_taken = 0;
	bool y = true;
 
	for(int i=1; i<=n; i++){
		if(vis[i] == 0){
			if(root_taken){
				y = false;
				break;
			}
			else{
				y &= dfs(i, 1) ;
				if(!y)	break;
				root_taken = true;
			}
		}
	}
 
	cout<< (y ? "YES" : "NO") << endl;
 
	return 0;
}
