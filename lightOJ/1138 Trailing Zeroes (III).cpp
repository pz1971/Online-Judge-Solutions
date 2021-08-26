#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int trailing_zeroes(int n){		// Legendre's formula
	int ret = 0 ;
	while(n){
		n /= 5 ;
		ret += n ;
	}
	return ret ;
}

int main(){

	int t, q ;
	scanf("%d", &t);

	for(int tc = 1; tc <= t ; tc++){
		scanf("%d", &q);

		int l = 5, u = INT_MAX, mid, ans = -1, val ;

		while(l <= u){
			mid = (l + u) >> 1 ;
			val = trailing_zeroes(mid) ;
			
			if(val == q){
				ans = mid ;
				u = mid - 1 ;
			}
			else if(val > q){
				u = mid - 1 ;
			}
			else{
				l = mid + 1 ;
			}
		}

		if(ans == -1){
			printf("Case %d: impossible\n", tc);
		}
		else{
			printf("Case %d: %d\n", tc, ans);
		}
	}

	return 0;
}