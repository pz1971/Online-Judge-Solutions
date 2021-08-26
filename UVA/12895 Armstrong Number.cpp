#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

LL powmod(LL base, LL exp, LL modulus = ((1ULL << 63) - 1ULL)){
	base %= modulus;
	long long result = 1;
	while (exp > 0) {
		if (exp & 1LL) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

LL number_of_digits(LL n){
	LL ret = 0LL ;
	while(n){
		ret++ ;
		n /= 10LL ;
	}
	return ret ;
}

bool is_armstrong(LL n){
	LL d = number_of_digits(n) ;
	LL n2 = n, x = 0LL ;

	while(n2){
		x = x + powmod((n2 % 10LL), d) ;
		n2 /= 10LL ;
		if(x > n)	break ;
	}
	if(x == n && n2 == 0LL)
		return true ;

	return false ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		LL n ;
		cin >> n ;
		cout << (is_armstrong(n) ? "Armstrong" : "Not Armstrong") << endl ;
	}

	return 0;
}