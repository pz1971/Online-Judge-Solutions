#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int t, n, i, ans;
    while(scanf("%d", &t)!=EOF)
    {
        for(i=1; i<=t; i++)
        {
            cin>> n;
            ans = (((n*567/9)+7492)*235/47)-498;
            ans = ans/10;
            ans = ans%10;
            ans = abs(ans);
            cout<< ans<< endl;
        }
    }
    return 0;
}
