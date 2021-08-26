#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, ar[100005] ;

int _lower_bound(const int x){			// bs to find the lower bound
	if(ar[0] >= x)		return 0 ;
	if(ar[n-1] < x)		return -1 ;
	
	int l = 0, u = n - 1, mid, ret = -1 ;
	
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

int _upper_bound(const int x){			// bs to find the upper bound
	if(ar[n-1] <= x)	return n - 1 ;
	if(ar[0] > x)		return -1 ;

	int l = 0, u = n - 1, mid, ret = -1 ;
	
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

int main(){

	int t ;
	scanf("%d", &t);

	for(int tc = 1 ; tc <= t ; tc++){
		int q ;
		scanf("%d %d", &n, &q);		// number of points, queries
		
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &ar[i]);
		sort(ar, ar + n) ;

		printf("Case %d:\n", tc);
		int a, b, l, u;
		
		for(int i = 0 ; i < q ; i++){
			scanf("%d %d", &a, &b);		// segment
			
			l = _lower_bound(a) ;
			u = _upper_bound(b) ;

			if(l == -1 || u == -1 || l > u){
				printf("0\n");
			}
			else{
				printf("%d\n", u-l+1);
			}
		}
	}

	return 0;
}