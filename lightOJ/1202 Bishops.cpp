#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	int r1, c1, r2, c2;
	int dx, dy, ans;

	scanf("%d", &t);
	for(int tc = 1; tc<= t; tc++){
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		dx = max((r1 - r2), 0 - (r1 - r2));
		dy = max((c1 - c2), 0 - (c1 - c2));
		
		if(dx == dy){
			ans = 1;
		}
		else if((dx + dy) % 2 == 0){
			ans = 2;
		}
		else{
			printf("Case %d: impossible\n", tc);
			continue;
		}

		printf("Case %d: %d\n", tc, ans);
	}

	return 0;
}