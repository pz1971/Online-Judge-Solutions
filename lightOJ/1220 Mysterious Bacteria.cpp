#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const int MX = 100000 ;
VI primes{2} ;
bool stat[MX] ;

void sieve(){
	for(int i = 3 ; i * i < MX ; i+=2){
		if(!stat[i]){
			primes.push_back(i) ;
			for(int j = i * i ; j < MX ; j+= i + i){
				stat[j] = true ;
			}
		}
	}

	for(int i = primes.back() + 2 ; i < MX ; i += 2){
		if(!stat[i])
			primes.push_back(i) ;
	}
}

void factorize(LL n, VI &vec){
	if(n < 0)	n = 0 - n ;

	for(auto i : primes){
		if(i * i > n)	break ;
		
		if(n % i == 0){
			vec.push_back(0) ;
			
			while(n % i == 0){
				vec.back()++ ;
				n /= i ;
			} 
		}
	}
	if(n > 1){
		vec.push_back(1) ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	sieve() ;

	int t;
	LL n ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n ;

		VI ar ;
		factorize(n, ar) ;
		sort(ar.begin(), ar.end()) ;

		cout<< "Case "<< tc<< ": ";

		if(ar.front() == 1){
			cout << 1 << endl ;
			continue ;
		}

		int mxP = 0 ;
		
		for(int i = 1 ; i <= ar.front() ; i++){
			bool y = true ;
			for(auto f : ar){
				if(f % i){
					y = false ;
					break ;
				}
			}

			if(y)
				mxP = i ;
			if(n < 0)	i++ ;
		}
		cout << mxP << endl ;
	}

	return 0;
}