#include <bits/stdc++.h>
using namespace std ;
typedef long long LL ;

map<string, map<string, bool>> ended_with_he ;

bool getName(string &str){
    str.clear() ;
    char ch ;
    bool ok = false ;
    while(scanf("%c", &ch) != EOF){
        ok = true ;
        if(!isalpha(ch))
            break ;
        str.push_back(ch) ;
    }
    return ok ;
}

bool is_hehe(const string &str){
    int s = 0 ,sum = 0;
    for(auto i : str){
        if(s == 0 && (i == 'h' || i == 'H')){
            s = 1 ;
        }
        else if(s == 1 && (i == 'e' || i == 'E')){
            s = 0 ;
            sum++ ;

        }
        else
            return false ;
    }

    return (sum >= 2 && s == 0) ;
}

bool has_hehe(string str){
    stringstream ss ;
    ss.clear() ;
    ss << str ;

    bool ret = false ;
    string word ;

    while(ss >> word){
        if(is_hehe(word)){
            ss.clear() ;
            return true ;
        }
    }

    return false ;
}

void func(string &str){
    for(auto &i : str){
        if(!isalpha(i))
            i = ' ' ;
    }
}

int main(){

    string fn, ln, sen ;

    while(getName(fn)){
        getchar() ;
        getName(ln) ;
        getchar() ;

        getline(cin, sen) ;
        func(sen) ;

        if(fn > ln) swap(fn, ln) ;
        ended_with_he[fn][ln] = has_hehe(sen) ;
    }

    int tot = 0 ;
    int cnt = 0 ;

    for(auto i : ended_with_he){
        for(auto j : i.second){
            tot++ ;
            if(j.second)
                cnt++ ;
        }
    }

    cout << round((cnt*1.0)/(tot*1.0) * 100.0) << '%' << endl ;

    return 0 ;
}