#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int _SIEVE_MX = 20000005;
bool stat[_SIEVE_MX];
// bitset<_SIEVE_MX> stat ;		// slower but memory efficient

void sieve(){
	for(int i = 3; i*i < _SIEVE_MX; i += 2){
		if(!stat[i]){
			for(int j = i*i; j < _SIEVE_MX; j += i+i)
				stat[j] = 1;
		}
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
	vector<pair<int,int> > pairs ;
	pairs.push_back({3, 5}) ;

	for(int p = 5 ; p + 2 <= 20000005 ; p += 6){
		if(isPrime(p) && isPrime(p + 2)){
			pairs.push_back({p, p + 2}) ;
		}
	}

	int n ;
	while(scanf("%d", &n) != EOF){
		printf("(%d, %d)\n", pairs[n-1].first, pairs[n-1].second);
	}

	return 0;
}