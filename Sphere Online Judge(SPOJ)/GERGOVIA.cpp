#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
int main(){
 
	int n, x, y;
 
	while(scanf("%d", &n) != EOF && n ){
		deque<PII> neg, pos;
 
		for(int i=0; i<n; i++){
			scanf("%d", &x);
			x < 0 ? neg.push_back(make_pair(0-x, i)) : pos.push_back(make_pair(x, i));
		}
 
		LL ans = 0;
 
		for(auto po: pos){
			x = po.first;
 
			while(x){
				y = min(neg[0].first, x);
				neg[0].first -= y;
				x -= y;
				ans += y * abs(neg[0].second - po.second);
 
				if(neg[0].first == 0)
					neg.pop_front();
			}
		}
 
		printf("%lld\n", ans);
	}
 
	return 0;
}
