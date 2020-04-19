#include <bits/stdc++.h>
using namespace std ;
typedef long long LL ;

int find(const string &s, char key){
    for(int i = 0 ; i < s.size() ; i++)
        if(s[i] == key)
            return i ;
    return -1 ;
}

string pre, in ;
map<char, int> val ;

int main(){

    while(cin >> pre >> in){
        for(int i = 0 ;i < pre.size() ; i++)
            val[pre[i]] = i ;


        stack<string> stk ;

        string str = "" ;
        str.push_back(pre.front()) ;
        stk.push(str) ;
        int pos = find(in, pre.front()) ;
        if(pos < in.size() - 1){
            stk.push(in.substr(pos + 1, in.size() - pos)) ;
        }
        if(pos > 0){
            stk.push(in.substr(0, pos)) ;
        }

        while(!stk.empty()){
            string cur = stk.top() ;
            stk.pop() ;

            if(cur.size() == 1){
                cout << cur ;
                continue ;
            }

            int mn = 200 ;
            char ch = 0 ;
            for(auto i : cur){
                if(val[i] < mn){
                    ch = i ;
                    mn = val[i] ;
                }
            }

            str = "" ;
            str.push_back(ch) ;
            stk.push(str) ;

            pos = find(cur, ch) ;

            if(pos < cur.size() - 1){
                stk.push(cur.substr(pos+1, cur.size() - pos)) ;
            }
            if(pos > 0){
                stk.push(cur.substr(0, pos)) ;
            }
        }
        cout << endl ;
    }

    return 0 ;
}