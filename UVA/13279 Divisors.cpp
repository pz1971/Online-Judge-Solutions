#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const LL mod = 100000007 ;
const int mx = 5000007 ;

LL powmod(LL base, LL exp, LL modulus = mod){
    base %= modulus;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1LL) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

vector<LL> primes{2LL} ;
int stat[mx] ;

void sieve(){
    for(int i = 3 ; i * i < mx ; i += 2){
        if(!stat[i]){
            primes.push_back((LL)i) ;
            for(int j = i * i ; j < mx ; j += i + i)
                stat[j] = 1 ;
        }
    }
    for(int j = primes.back() + 2 ; j < mx ; j += 2)
        if(!stat[j])
            primes.push_back((LL)j) ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sieve() ;
    const LL half = powmod(2LL, mod-2) ;

    LL n ;
    while(cin >> n){
        if(!n)  break ;

        LL ans = 1LL, a, b, N, sum ;
        for(auto i : primes){
            if(i > n)
                break ;
                
            LL p = 1LL ;
            for(LL j = i ; j <= n ; j *= i){
                b = n - j + 1LL ;
                N = n / j ;
                a = n - N * j + 1LL ;
                sum = (((((a + b) % mod) * N) % mod) * half) % mod ;
                p = (p + sum) % mod ;
            }
            ans = (ans * p) % mod ;
        }
        cout << ans << endl ;
    }

    return 0;
}