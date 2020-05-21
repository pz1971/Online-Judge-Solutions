#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class order{
public: 
	int s, d, p ;
	order(){
	}
	order(int s, int d, int p){
		this -> s = s ;
		this -> d = d ;
		this -> p = p ;
	}
} ;

class cmp{
public:
	bool operator () (const order &a, const order &b){
		if(a.s < b.s)
			return true ;
		if(a.s == b.s && a.d < b.d)
			return true ;
		if(a.s == b.s && a.d == b.d)
			return a.p > b.p ;
		return false ;
	}
} ;

int n ;
vector<order> ar ;
vector<int> dp ;

int func(int i){
	if(i == n)
		return 0 ;
	if(dp[i] > 0)	return dp[i] ;
	
	int x = 0 ;
	for(int j = i + 1 ; j < n ; j++){
		if(ar[i].s + ar[i].d <= ar[j].s)
			x = max(x, func(j)) ;
	}

	return dp[i] = ar[i].p + x ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		cin >> n ;
		ar = vector<order> (n) ;
		dp = vector<int> (n, 0) ;
		for(auto &i : ar){
			cin >> i.s >> i.d >> i.p ;
		}
		sort(ar.begin(), ar.end(), cmp()) ;
		
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++)
			ans = max(ans, func(i)) ;
		cout << ans << endl ;
	}

	return 0;
}