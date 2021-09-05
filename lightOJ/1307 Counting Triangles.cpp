#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, ar[2005] ;

int _upper_bound(const int a, const int b, int l, int x){
	int u = n - 1, mid, ret = -1 ;
	
	while(l <= u){
		mid = (l + u) >> 1 ;
		
		if(ar[mid] <= x){
			ret = mid ;
			l = mid + 1 ;
		}
		else{
			u = mid - 1 ;
		}
	}

	return ret ;
}

int _lower_bound(const int a, const int b, int l, int x){
	int u = n - 1, mid, ret = -1 ;
	
	while(l <= u){
		mid = (l + u) >> 1 ;
		
		if(ar[mid] >= x){
			ret = mid ;
			u = mid - 1 ;
		}
		else{
			l = mid + 1 ;
		}
	}

	return ret ;
}

int main(){

	int t ;
	scanf("%d", &t);

	for(int tc = 1 ; tc <= t ; tc++){
		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++)
			scanf("%d", &ar[i]);
		sort(ar, ar + n) ;

		int cnt = 0 ;

		for(int i = 0 ; i + 2 < n ; i++){
			for(int j = i + 1 ; j < n ; j++){
				int u = _upper_bound(ar[i], ar[j], j+1, ar[i] + ar[j] - 1) ;
				int l = _lower_bound(ar[i], ar[j], j+1, max(ar[i], ar[j])) ;

				if(l == -1 || u == -1 || u < l)
					cnt += 0 ;
				else 
					cnt += u - l + 1 ;
			}
		}

		printf("Case %d: %d\n", tc, cnt);
	}

	return 0;
}