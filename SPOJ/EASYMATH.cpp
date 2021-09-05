#include <bits/stdc++.h>
#define vi vector<int>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
 
int main()
{
 
    llu n, m, a, d, a2, a3, a4, a5, cnt{}, x;
    int t{};
    cin>> t;
    while(t--)
    {
        cin>> n>> m>> a>> d;
        a2 = a+d;   a3 = a2+d;  a4 = a3+d;  a5 = a4+d;
 
        if(a!=1)
        {
            x = n/a;
            if(n%a!=0)
                x++;
            cnt = (m/a) - x + 1;
 
            if(a2%a!=0)
            {
                if(n%a2!=0)
                    x =  n - (n%a2) + a2;
                else
                    x = n;
                for( ; x<=m; x+=a2)
                {
                    if(x%a!=0)
                        cnt++;
                }
            }
 
            if(a3%a2!=0 && a3%a!=0)
            {
                if(n%a3!=0)
                    x = n - (n%a3) + a3;
                else
                    x = n;
                for( ; x<=m; x+=a3)
                {
                    if(x%a2!=0 && x%a!=0)
                        cnt++;
                }
            }
 
            if(a4%a3!=0 && a4%a2!=0 && a4%a!=0)
            {
                if(n%a4!=0)
                    x = n - (n%a4) + a4;
                else
                    x = n;
                for( ; x<=m; x+=a4)
                {
                    if(x%a3!=0 && x%a2!=0 && x%a!=0)
                        cnt++;
                }
            }
 
            if(a5%a4!=0 && a5%a3!=0 && a5%a2!=0 && a5%a!=0)
            {
                if(n%a5!=0)
                    x = n - (n%a5) + a5;
                else
                    x = n;
                for( ; x<=m; x+=a5)
                {
                    if(x%a4!=0 && x%a3!=0 && x%a2!=0 && x%a!=0)
                        cnt++;
                }
            }
            cout<< m-n+1-cnt<< endl;
        }
        else
            cout<< "0"<< endl;
    }
 
    return 0;
}