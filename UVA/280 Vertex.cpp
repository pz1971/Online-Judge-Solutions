#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n;
VI g[105];
int vis[105];

void dfs(int root){
	for(auto i: g[root]){
		if(!vis[i]){
			vis[i] = 1;
			dfs(i);
		}
	}
}

int main(){

	int u, v;
	while(scanf("%d", &n) != EOF && n != 0){
		for(int i=1; i<=n ; i++)
			g[i].clear();

		while(scanf("%d", &u) != EOF && u != 0){
			while(scanf("%d", &v) != EOF && v != 0){
				g[u].push_back(v);
			}
		}

		scanf("%d", &u);
		while(u--){
			memset(vis, 0, sizeof vis);
			
			scanf("%d", &v);
			dfs(v);

			VI list_of_inaccessible;
			for(int i = 1; i <= n; i++)
				if(!vis[i])
					list_of_inaccessible.push_back(i);
			
			printf("%d", (int) list_of_inaccessible.size());
			for(int i: list_of_inaccessible)
				printf(" %d", i);
			printf("\n");
		}
	}

	return 0;
}