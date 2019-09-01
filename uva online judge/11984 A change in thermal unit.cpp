#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t, i;
    double c, d, ans;
    cin>> t;
    for(i=1; i<=t; i++)
    {
        cin>> c>> d;
        printf("Case %d: ", i);
        ans = c + (d*5/9);
        printf("%.2lf\n", ans);
    }
    return 0;
}

