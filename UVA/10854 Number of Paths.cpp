#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int execute(){
    string command ;
    int ret = 0 ;
    int c = 1 ;

    while(cin >> command){
        if(command == "S")
            continue ;
        else if(command == "IF"){
            c *= execute() ;
        }
        else if(command == "ELSE"){
            ret += c ;
            c = 1 ;
        }
        else{
            ret += c ;
            break ;
        }
    }
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int ans = 1 ;
        string command ;
        while(cin >> command){
            if(command == "ENDPROGRAM"){
                cout << ans << endl ;
                break ;
            }
            else if(command == "S")
                continue ;
            else {
                ans *= execute() ;
            }
        }
    }

    return 0;
}