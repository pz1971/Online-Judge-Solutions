#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
    int t, i, j, n1, n2, yes=1;
    string a, b;
    while(scanf("%d", &t)!=EOF)
    {
        for(j=1; j<=t; j++)
        {
            cin>> a>> b;
            n1 = a.size();
            n2 = b.size();
            yes = 1;
            if(n1==n2)
            {
                for(i=0; i<n1; i++)
                {
                    if(a[i]!=b[i])
                    {
                        if(a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o' && a[i]!='u')
                        {
                            yes = 0;
                            break;
                        }
                        else if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
                        {
                            if(b[i]!='a' && b[i]!='e' && b[i]!='i' && b[i]!='o' && b[i]!='u')
                            {
                                yes = 0;
                                break;
                            }
                        }
                    }
                }
                if(yes==1)
                    printf("Yes\n");
                else if(yes==0)
                    printf("No\n");
            }
            else
                cout<< "No"<< endl;
        }
    }
    return 0;
}
