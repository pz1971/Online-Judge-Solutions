#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll reve(ll n)
{
    ll n2{};
    while(n)
    {
        n2 = n2*10 + n%10;
        n /= 10;
    }
    return n2;
}
int main()
{
    size_t t;
    while(cin>> t)
    {
        while(t--)
        {
            ll n{}, n2{};
            cin>> n;
            n2 = reve(n);
            int cnt{};
            while(n != n2)
            {
                n += n2;
                cnt++;
                n2 = reve(n);
            }
            cout<< cnt<< " "<< n << endl;
        }
    }
    return 0;
}
