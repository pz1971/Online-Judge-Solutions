#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int num[1005];

void bfs( VI g[]){
	memset(num, 0, sizeof num);

	num[0] = 1;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int temp = q.front();
		q.pop();

		for(int i: g[temp]){
			if(num[i])	continue;
			num[i] = num[temp] + 1;
			q.push(i);
		}
	}

}

int main(){

	int t;
	scanf("%d", &t);
	while(t--){
		int p, d;
		scanf("\n%d %d", &p, &d);
		VI g[p];
		int a, b;
		while(d--){
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		bfs(g);
		for(int i=1; i<p; i++){
			printf("%d\n", num[i]-1);
		}
		if(t)	printf("\n");
	}

	return 0;
}