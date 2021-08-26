#include <bits/stdc++.h>
#define nl printf("\n")
using namespace std;
//typedef long long ll;
//typedef unsigned long long llu;
void scanf(int &n)
{
    bool negative = false;
    char c;
    n = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        n = n*10 + c - 48;
    if (negative)
        n *= -1;
}
int main()
{
    int t, n{}, a{};
    scanf(t);
    for(int i=1; i<=t; i++)
    {
        scanf(n);
        int mile{}, juice{};
        while(n--)
        {
            scanf(a);
            a++;
            mile += a/30*10;
            juice += a/60*15;
            if(a%30!=0)
                mile += 10;
            if(a%60!=0)
                juice += 15;
        }
        printf("Case %d: ", i);
        if(juice < mile)
            printf("Juice %d", juice);
        else if(mile < juice)
            printf("Mile %d", mile);
        else
            printf("Mile Juice %d", juice);
        nl;
    }
    return 0;
}
