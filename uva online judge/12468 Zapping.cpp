#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
    {
        if(a==-1 && b==-1)
            break;
        a = abs(a-b);
        if(a>50)
            a = 100-a;
        printf("%d\n", a);
    }
    return 0;
}
