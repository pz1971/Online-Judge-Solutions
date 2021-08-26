#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t, i, e, f, c, ans;
    while(scanf("%d", &t)!=EOF)
    {
        for(i=1; i<=t; i++)
        {
            ans = 0;
            cin>> e>> f>> c;
            e+= f;
            while(1)
            {
                if(e<c)
                    break;
                ans+= e/c;
                e = e%c + e/c;
            }
            cout<< ans<< endl;
        }
    }
    return 0;
}
