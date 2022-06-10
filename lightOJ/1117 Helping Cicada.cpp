#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

vector<LL> ar ;
vector<LL> L ;

LL LCM(LL a, LL b)
{
    return (a / __gcd(a, b)) * b ;
}

LL n, m ;
LL func()
{   
    LL g = L.front() ;
    for(auto i : L)
        g = LCM(g, i) ;

    // cout << L.size() << ": " ;
    // for(auto i: L)
    //     cout << i << " " ;
    // cout << " : " << n / g ;
    // cout << endl ;

    return n / g ;
}

LL ans ;
void select(int pos, const int count)
{
    if(L.size() == count)
    {
        ans += func() * (count % 2 == 0 ? 1 : -1) ;
        return ;
    }
    if(pos == m)
        return ;

    select(pos + 1, count) ;
    L.push_back(ar[pos]) ;
    select(pos + 1, count) ;
    L.pop_back() ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++)
    {
        cin >> n >> m ;
        ar.resize(m) ;
        L.clear() ;
        for(auto &i : ar)
            cin >> i ;
        sort(ar.begin(), ar.end()) ;

        if(ar.front() == 1)
        {
            cout<< "Case "<< tc<< ": 0" << endl ;
            continue ;
        }

        ans = n ;
        for(int i = 1 ; i <= m ; i++)
            select(0, i) ;
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}