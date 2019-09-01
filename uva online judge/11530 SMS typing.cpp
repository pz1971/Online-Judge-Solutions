#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t, i, j, k, ans;
    char m[105];
    while(scanf("%d", &t)!=EOF)
    {
        getchar();
        for(i=1; i<=t; i++)
        {
            ans = 0;
            for(k=0; k<105; k++)
            {
                scanf("%c", &m[k]);
                if(m[k]=='\n')
                {
                    m[k] = '\0';
                    break;
                }
            }
            for(j=0; j<=k; j++)
            {
                switch(m[j])
                {
                case ' ':
                    ans+=1;
                    break;
                case 'a':
                    ans+=1;
                    break;
                case 'b':
                    ans+=2;
                    break;
                case 'c':
                    ans+=3;
                    break;
                case 'd':
                    ans+=1;
                    break;
                case 'e':
                    ans+=2;
                    break;
                case 'f':
                    ans+=3;
                    break;
                case 'g':
                    ans+=1;
                    break;
                case 'h':
                    ans+=2;
                    break;
                case 'i':
                    ans+=3;
                    break;
                case 'j':
                    ans+=1;
                    break;
                case 'k':
                    ans+=2;
                    break;
                case 'l':
                    ans+=3;
                    break;
                case 'm':
                    ans+=1;
                    break;
                case 'n':
                    ans+=2;
                    break;
                case 'o':
                    ans+=3;
                    break;
                case 'p':
                    ans+=1;
                    break;
                case 'q':
                    ans+=2;
                    break;
                case 'r':
                    ans+=3;
                    break;
                case 's':
                    ans+=4;
                    break;
                case 't':
                    ans+=1;
                    break;
                case 'u':
                    ans+=2;
                    break;
                case 'v':
                    ans+=3;
                    break;
                case 'w':
                    ans+=1;
                    break;
                case 'x':
                    ans+=2;
                    break;
                case 'y':
                    ans+=3;
                    break;
                case 'z':
                    ans+=4;
                    break;
                }
            }
            printf("Case #%d: ", i);
            cout<<ans<<endl;
        }
    }
    return 0;
}
