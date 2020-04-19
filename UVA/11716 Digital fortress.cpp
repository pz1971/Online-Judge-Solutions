#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int i, j, t, n, k;
    char str[10000], c;
    while(scanf("%d", &t)!=EOF)
    {
        scanf("%c", &c);
        for(k=1; k<=t; k++)
        {
            for(i=0; i<10000; i++)
            {
                str[i] = getchar();
                if(str[i]=='\n')
                {
                    str[i] = '\0';
                    break;
                }
            }
            n = i;
            if( n != (int)sqrt(n) * (int)sqrt(n) )
                cout<< "INVALID";
            else
            {
                n = (int)sqrt(n);
                for(i=0; i<n; i++)
                {
                    for(j=0; j<n; j++)
                        cout<< str[i+(n*j)];
                }
            }
            cout<< endl;
        }
    }
    return 0;
}
