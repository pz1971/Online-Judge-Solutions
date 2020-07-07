#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int _SIEVE_MX = 5000005;
bool stat[_SIEVE_MX];
vector<int> primes{2};

void sieve(){
	for(int i = 3; i*i < _SIEVE_MX; i += 2){
		if(!stat[i]){
			primes.push_back(i);
			for(int j = i*i; j < _SIEVE_MX; j += i+i)
				stat[j] = 1;
		}
	}

	for(int i = primes.back() + 2; i < _SIEVE_MX; i += 2){
		if(!stat[i])
			primes.push_back(i);
	}
}

vector<int> S ;

void span(const vector<int> &ar){
	S.clear() ;
	stack<pair<int, int> > stk ;
	stk.push(make_pair(INT_MAX , -1)) ;

	for(int i = 0 ; i < ar.size() ; i++){
		while(ar[i] >= stk.top().first)
			stk.pop() ;
		
		S.push_back(i - stk.top().second) ;
		stk.push(make_pair(ar[i], i)) ;
	}
}

int main(){

	sieve() ;

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		cin >> n >> m ;
		vector<int> X ;
		for(int i = 0 ; i < n ; i++){
			X.push_back(primes[i] % m) ;
		}

		span(X) ;

		int ans = 0 ;
		for(auto i : S){
			ans = (ans + i) % m ;
		}
		cout << ans << endl ;
	}

	return 0;
}