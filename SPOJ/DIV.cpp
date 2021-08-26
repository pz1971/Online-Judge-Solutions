#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
const int MX = 1005;
bool stat[MX];
bool nod_OK[250] ;		// maximum NOD for all N is 240 (calculated using another program :P )
vector<int> primes{2};
 
void sieve(){
	for(int i = 4 ; i < MX ; i+=2)
		stat[i] = 1 ;
	for(int i = 3; i*i < MX; i += 2){
		if(!stat[i]){
			primes.push_back(i);
			for(int j = i*i; j < MX; j += i+i)
				stat[j] = 1;
		}
	}
 
	for(int i = primes.back(); i < MX; i += 2){
		if(!stat[i])
			primes.push_back(i);
	}
}
 
int NOD(int n){			// number of divisors of n
    int cnt = 1, x = 0;
    
	for(auto i : primes){
		if(i * i > n)	break ;
		if(n % i == 0){
			x = 0 ;
			while(n % i == 0){
				n /= i ;
				x++ ;
			}
			cnt *= (x + 1) ;
		}
	}
 
    if(n > 1){
        cnt *= 2;
    }
    return cnt;
}
 
bool OK(int n){		// determines the NOD is ok or not
	if(stat[n] == 0)
		return false ;	// a prime can't be represented as prime2 * prime3
 
	int a_divisor = INT_MAX ;
	for(auto i : primes){
		if(n % i == 0){
			a_divisor = i ;
			n /= i ;
			break ;
		}
	}
 
	if(n % a_divisor == 0)
		return false ;	// divisible by a_divisor ^ (x) where x > 1, so- n can't be == prime1 * prime2
	
	return (stat[n] == 0) ;		// n = a_divisor * (n / a_divisor) where both a_divisor and (n / a_divisor) are primes
}
 
int main(){
	
	sieve() ;
 
	for(int i = 1 ; i < 250 ; i++){
		nod_OK[i] = OK(i) ;
	}
 
	int cnt = 0 ;
	for(int i = 1 ; i < 1000001 ; i++){
 
		if( nod_OK[ NOD( i ) ]) {
			cnt++ ;
 
			if(cnt && cnt % 9 == 0){
				printf("%d\n", i) ;
			}
		}
		
	}
 
	return 0;
}
