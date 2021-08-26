#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const LL mod = 100000007 ;
const int mx = 10000007 ;

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

LL fact[mx], i_fact[mx], pow_2[mx] ;

void pre(){
    fact[0] = pow_2[0] = 1LL ;
    for(LL i = 1 ; i < mx ; i++){
        fact[i] = (fact[i - 1] * i) % mod ;
        pow_2[i] = (pow_2[i-1] * 2LL) % mod ;
    }
    
    i_fact[mx-1] = powmod(fact[mx-1], mod - 2) ;
    for(LL i = mx - 2 ; i >= 0 ; i--)
        i_fact[i] = (i_fact[i + 1] * (i + 1)) % mod ;
}

inline LL nCr(LL n, LL r){
    return (fact[n] * ((i_fact[n - r] * i_fact[r]) % mod)) % mod ;
}

LL f(LL n){
    switch (n){
    case 1LL :     return 1LL ;
    case 2LL :     return 14LL; // 4C1+4C2+4C3
    case 3LL :     return 36LL; // 4C1(3C1+3C2)+4C2*2C1
    default  :     return 24LL; // 4C1*3C1*2C1*1C1 = 4!
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    pre() ;

    LL n ;
    while(cin >> n){
        if(!n)
            break ;
        LL ans = 0 ;
        for(LL i = 1 ; i <= min(4LL, n) ; i++){
            ans = (ans + (nCr(n, i) * (pow_2[n - i] * f(i)) % mod) % mod) % mod ;
        }
        cout << ans << endl ;
    }

    return 0;
}