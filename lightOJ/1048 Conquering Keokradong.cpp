#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, k , ar[1005] ;

int day_count(const int mx_dis){
	int cnt = 0, cur = 0 ;

	for(int i = 0; i < n; i++){
		if(ar[i] > mx_dis)
			return INT_MAX ;
		
		if(cur < ar[i]){
			cnt++ ;
			cur = mx_dis ;
		}

		cur -= ar[i] ;
	}

	return cnt ;
}

void print_distances_per_day(const int mx_dis){
	vector< VI > 	vec ;
	vec.push_back( VI() ) ;

	int cur = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(cur + ar[i] > mx_dis){
			cur = 0 ;
			vec.push_back( VI() ) ;
		}

		cur += ar[i] ;
		vec.back().push_back(ar[i]) ;
	}

	stack<int>	stk ;
	
	while(vec.size() + stk.size() < k){
		stk.push(vec.back().back()) ;
		vec.back().pop_back() ;
		
		if(vec.back().empty())
			vec.pop_back() ;
	}

	for(const VI &v : vec){
		cout<< accumulate(v.begin(), v.end(), 0) << endl ;		// sum of all elements ;
	}

	while(!stk.empty()){
		cout << stk.top() << endl ;
		stk.pop() ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n >> k ;
		n++ ;	k++ ;		// total number of distances = n+1, nights = k, thus days = k+1

		for(int i=0; i < n; i++)
			cin >> ar[i] ;

		int cnt , l = 0, u = n * 10000, mid ;

		while(l < u){		// finding the minimum of maximum distances
			mid = (l + u) / 2 ;
			cnt = day_count(mid) ;

			if(cnt > k){
				l = mid + 1 ;
			}
			else{
				u = mid ;
			}
		}

		cout<< "Case "<< tc << ": " << l << endl;
		print_distances_per_day( l ) ;
	}

	return 0;
} 
