#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

LL mod ;
map<LL, LL> F ;

LL f(LL n) {
	if (F.count(n)) return F[n] ;
	LL k = n/2 ;
	
	if (n % 2 == 0) { // n=2*k
		return F[n] = ((f(k)*f(k)) % mod + (f(k-1)*f(k-1)) % mod) % mod ;
	}
	else{ // n=2*k+1
		return F[n] = ((f(k)*f(k+1) % mod) + (f(k-1)*f(k)) % mod) % mod ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	LL n, prevMod = - 1;
	while(cin >> n >> mod){
		mod = (1LL << mod) ;

		if(mod != prevMod){
			F.clear() ;
			F[0] = F[1] = 1 % mod ;
			prevMod = mod ;
		}

		cout << (n == 0 ? 0 % mod : f(n - 1)) << endl ;
	}

	return 0;
}