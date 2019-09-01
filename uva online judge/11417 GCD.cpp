#include<iostream>
#include<cstdio>
int gcd(int x, int y);
using namespace std;
int main()
{
    int n, g, i, j;

    while(1)
    {
        cin>> n;
        if(n==0)
            break;
        g = 0;
        for(i=1; i<n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                g += gcd(i,j);
            }
        }
        cout<< g<< endl;
    }
    return 0;
}
int gcd(int x, int y)
{
    int i, p, ans;
    if(x>y)
    {
        p = x;
        x = y;
        y = p;
    }
    ans = 1;
    for(i=2; i<=x; i++)
    {
        if(x%i==0)
        {
            if(y%i==0)
                ans = i;
        }
    }
    return ans;
}
