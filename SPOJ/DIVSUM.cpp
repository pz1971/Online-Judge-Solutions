#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
const LL MX = 500000;
bitset<MX> stat;
vector<LL> primes{2};
 
void sieve(){
	for(int i = 3; i*i < MX; i += 2){
		if(!stat[i]){
			primes.push_back(i);
			for(LL j = i*i; j < MX; j += i+i)
				stat[j] = 1;
		}
	}
 
	for(LL i = primes.back() + 2 ; i < MX; i += 2){
		if(!stat[i])
			primes.push_back(i);
	}
}
 
LL power(LL b, LL p){
    if(p == 0)  return 1LL;
    LL ret = power(b , p/2);
    ret *= ret;
    if(p % 2)   ret *= b;
    return ret;
}
 
LL SOD(LL n){
    LL ret = 1, x = 0;
    for(auto i : primes){
        if(i * i > n)	break ;
 
		if(n % i == 0){
            x = 0;
            while(n % i == 0){
                n /= i;
                x++;
            }
            ret *= (power(i, ++x) - 1) / (i - 1);
        }
    }
    if(n > 1){
		ret *= (n + 1) ;
	}
 
    return ret;
}
 
int main(){
 
	sieve() ;
	int t;
	LL n;
 
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", SOD(n)-n) ;
	}
 
	return 0;
}