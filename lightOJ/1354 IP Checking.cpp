#include<stdio.h>
#include<math.h>
int btod(int x);
int main()
{
    int t, i, ip1, ip2, ip3, ip4, bip1, bip2, bip3, bip4;
    char a, b, c;
    while(scanf("%d", &t)!=EOF)
    {
        for(i=1; i<=t; i++)
        {
            scanf("%d%c%d%c%d%c%d", &ip1, &a ,&ip2 ,&b ,&ip3 ,&c ,&ip4);
            scanf("%d%c%d%c%d%c%d", &bip1, &a ,&bip2 ,&b ,&bip3 ,&c ,&bip4);

            bip1 = btod(bip1);
            bip2 = btod(bip2);
            bip3 = btod(bip3);
            bip4 = btod(bip4);

            if(ip1==bip1 && ip2==bip2 && ip3==bip3 && ip4==bip4)
                printf("Case %d: Yes\n", i);
            else
                printf("Case %d: No\n", i);
        }
    }
    return 0;
}
int btod(int x)
{
    int d=0, i;
    for(i=0 ; x>=1; x/=10, i++)
    {
        d += (x%10)*pow(2, i);
    }
    return d;
}