#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int _SIEVE_MX = 10000005;
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

bool isPrime(int n){
	if(n > 1 && n < 4)
		return true;
	if(n % 2 == 0 || n == 1)
		return false;
	return (stat[n] == 0);
}

int main(){

	sieve() ;
	
	int n ;
	
	while(cin >> n){
		if(n < 8){
			cout << "Impossible." << endl ;
			continue ;
		}
		else if(n < 10){
			cout << "2 2 2 " << (n - 6) << endl ;
			continue ;
		}

		cout << 2 << " " << (2 + (n & 1)) << " " ;
		n -= 4 + (n & 1) ;

		for(auto i : primes){
			if(isPrime(n-i)){
				cout << i << " "<< n-i << endl ;
				break ;
			}
		}
	}

	return 0;
}