#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using   namespace __gnu_pbds ;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset ;

class query{
public:
    int k, i, l, id ;
    query(){ }
} ;
class cmp{
public:
    bool operator () (const query &a, const query &b){
        return a.i < b.i or (a.i == b.i and a.k < b.k) ;
    }
} ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q ;
    cin >> n >> q ;
    
    vector<int> ar(n) ;
    map<int, vector<int> > occ ;
    for(int i = 0 ; i < n ; i++){
        cin >> ar[i] ;
        occ[ar[i]].push_back(i) ;
    }

    vector<query> queries(q) ;
    for(int i = 0 ; i < q ; i++){
        queries[i].id = i ;
        cin >> queries[i].k >> queries[i].i >> queries[i].l ;
    }
    sort(queries.begin(), queries.end(), cmp()) ;

    vector<int> ans(q) ;
    ordered_multiset oms ;

    int cur = 0, p ;
    for(auto qq : queries){
        while(oms.size() <= qq.i)
            oms.insert(ar[cur++]) ;
        p = *oms.find_by_order(qq.k-1) ;

        if(qq.l > occ[p].size())
            ans[qq.id] = -1 ;
        else 
            ans[qq.id] = occ[p][qq.l - 1] ;
    }

    for(auto i : ans)
        cout << i << endl ;

    return 0;
}