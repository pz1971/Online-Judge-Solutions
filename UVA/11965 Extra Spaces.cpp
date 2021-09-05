#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        cin >> n ;
        cin.ignore() ;
        string s, s2 ;

        cout<< "Case "<< tc<< ":" << endl ;
        for(int i = 0 ; i < n ; i++){
            s2.clear() ;
            getline(cin, s) ;
            for(int j = 0 ; j < s.size() ; j++){
                if(s[j] == ' ' and j > 0 and s[j-1] == ' ')
                    continue ;
                s2.push_back(s[j]) ;
            }
            cout << s2 << endl ;
        }

        if(tc < test_cases)
            cout << endl ;
    }

    return 0;
}