#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int MX = 100005 ;
int dis[MX] ;
vector<pair<int, int> > critical_links ;
vector<int> g[MX] ;

int discovery ;
void clear(int n){
    for(int i = 0 ; i < n ; i++){
        g[i].clear() ;
        dis[i] = 0 ;
    }
    critical_links.clear() ;
    discovery = 0 ;
}

int dfs(int u, int par){
    dis[u] = ++discovery ;
    int ret = dis[u] , temp ;

    for(int v : g[u]){
        if(v == par)
            continue ;
        if(dis[v] == 0){
            temp = dfs(v, u) ;
            if(temp > dis[u])
                critical_links.push_back(make_pair(min(u, v), max(u, v))) ;
            ret = min(ret, temp) ;
        }
        else{
            ret = min(ret, dis[v]) ;
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
        int n ;
        cin >> n ;
        clear(n) ;

        int u, k, v ;
        char ch ;

        for(int i = 0 ; i < n; i++){
            cin >> u >> ch >> k >> ch ;
            while(k--){
                cin >> v ;
                g[u].push_back(v) ;
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(dis[i] == 0){
                dfs(i, -1) ;
            }
        }

        cout<< "Case "<< tc<< ":" << endl ;
        cout << critical_links.size() << " critical links" << endl ;
        sort(critical_links.begin(), critical_links.end()) ;
        for(auto link : critical_links)
            cout << link.first << " - " << link.second << endl ;
    }

    return 0;
}