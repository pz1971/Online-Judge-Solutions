#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int mod = 912 ;
const int mx = 1e3 + 5 ;
int dp[mx][mx] ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0 ; i < mx ; i++){
        for(int j = 0 ; j < mx ; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 1 ;
            else 
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        cout<< "Case "<< tc<< endl ;
        int R, C, Q ;
        cin >> R >> C >> Q ;

        R--, C-- ;
        int a, b, c, d ;
        
        for(int qq = 1 ; qq <= Q ; qq++){
            cin >> a >> b >> c >> d ;
            cout << "   Query " << qq << ": " ;

            if((a == 0 && b == 0) || (c == R && d == C)){
                cout << 0 << endl ;
                continue ;
            }

            int ans = 0 ;

            int x = c + 1 ;
            int y = b - 1 ;
            while(x <= R && y >= 0){
                ans = (ans + ((dp[x][y] * dp[R-x][C-y]) % mod)) % mod ;
                x++ ; y-- ;
            }

            x = a - 1 ;
            y = d + 1 ;
            while(x >= 0 && y <= C){
                ans = (ans + ((dp[x][y] * dp[R-x][C-y]) % mod)) % mod ;
                x-- ; y++ ;
            }

            cout << ans << endl ;
        }
    }

    return 0;
}