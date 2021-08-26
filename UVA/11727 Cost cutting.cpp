#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int t, s[3], i;
    while(scanf("%d", &t)!=EOF)
    {
        for(i=1; i<=t; i++)
        {
            cin>> s[0]>> s[1]>> s[2];
            sort(s, s+3);
            printf("Case %d: %d\n", i, s[1]);
        }
    }
    return 0;
}
