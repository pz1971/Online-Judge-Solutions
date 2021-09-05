// alomst similar to uva 11413

#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, m , ar[1005] ;

int count_for_it(const int mx_cap){
	int cnt = 0, cur_cap = 0 ;

	for(int i= 0; i<n; i++){
		if(ar[i] > mx_cap)
			return INT_MAX ;
		if(cur_cap < ar[i]){
			cnt++ ;
			cur_cap = mx_cap ;
		}

		cur_cap -= ar[i] ;
	}

	return cnt ;
}

int main(){

	int t ;
	scanf("%d", &t);

	for(int tc = 1 ; tc <= t ; tc++){
		scanf("%d %d", &n, &m);
		
		for(int i=0; i < n; i++)
			scanf("%d", &ar[i]);
		
		int cnt , l = 1, u = n * 1000000, mid ;
		
		while(l < u){
			mid = (l + u) / 2 ;
			cnt = count_for_it(mid) ;

			if(cnt > m){
				l = mid + 1 ;
			}
			else{
				u = mid ;
			}
		}

		printf("Case %d: %d\n", tc, l);
	}

	return 0;
}