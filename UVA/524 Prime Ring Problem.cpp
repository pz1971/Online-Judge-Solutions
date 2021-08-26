#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37} ;

inline bool is_prime(int n){
    return binary_search(primes.begin(), primes.end(), n) ;
}

bool check(const vector<int> &ar){
    for(int i = 0 ; i < ar.size() ; i++){
        if(!is_prime(ar[i] + ar[(i+1) % ar.size()]))
            return false ;
    }
    return true ;
}

vector<int> g[17] ;
int vis[17] ;

vector<vector<int> > ar ;
vector<int> cur ;

void dfs(int u, const int mx){
    if(u > mx)
        return ;
    cur.push_back(u) ;
    vis[u] = 1 ;
    for(auto &v : g[u]){
        if(!vis[v] and v <= mx)
            dfs(v, mx) ;
    }

    if(cur.size() == mx and check(cur)){
        ar.push_back(cur) ;
    }
    cur.pop_back() ;
    vis[u] = 0 ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1 ; i <= 16 ; i++){
        for(int j = i + 1 ; j <= 16 ; j++){
            if(is_prime(i + j)){
                g[i].push_back(j) ;
                g[j].push_back(i) ;
            }
        }
    }

    vector<vector<int> > ans[17] ;
    for(int i = 1 ; i <= 16 ; i++){
        ar.clear() ;
        cur.clear() ;
        dfs(1, i) ;
        ans[i] = ar ;
    }
    
    int n, tc = 0 ;
    while(cin >> n){
        if(tc)  cout << endl ;
        cout<< "Case "<< ++tc<< ":" << endl ;

        for(auto &i : ans[n]){
            for(int j = 0 ; j < i.size() ; j++){
                if(j)   cout << " " ;
                cout << i[j] ;
            }
            cout << endl ;
        }
    }

    return 0;
}