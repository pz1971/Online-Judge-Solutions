#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

inline int f(char ch){
    switch (ch){
        case '(':   return 0 ;
        case ')':   return 1 ;
        case '{':   return 2 ;
        case '}':   return 3 ;
        case '[':   return 4 ;
        case ']':   return 5 ;
        case '<':   return 6 ;
        default :   return 7 ;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    cin.ignore() ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        string s ;
        cin >> s ;

        stack<int> stk ;
        vector<int> ar(s.size()) ;

        for(int i = 0 ; i < s.size() ; i++){
            if(f(s[i]) % 2 == 0){
                stk.push(i) ;
            }
            else{
                if(stk.empty())
                    continue ;

                int a = stk.top() ;
                stk.pop() ;

                if(f(s[a]) != f(s[i]) - 1){
                    while(!stk.empty())
                        stk.pop() ;
                }
                else{
                    ar[a] = i - a + 1 ;
                }
            }
        }

        ar.push_back(0) ;
        for(int i = ar.size() - 2 ; i >= 0 ; i--){
            ar[i] += ar[i + ar[i]] ;
        }
        ar.pop_back() ;

        cout<< "Case "<< tc<< ":" << endl ;
        for(auto i : ar)
            cout << i << endl ;
    }

    return 0;
}