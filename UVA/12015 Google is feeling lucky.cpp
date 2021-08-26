#include<bits/stdc++.h>
using namespace std;
int main()
{
    size_t t, tc;
    while(cin>> t)
    {
        getchar();
        for(tc=1; tc<=t; tc++)
        {
            char str[10][10000], ch;
            int n[10], indx[10];
            for(int i=0; i<10; i++)
            {
                int j{};
                while(1)
                {
                    ch = getchar();
                    if(!isspace(ch))
                    {
                        str[i][j] = ch;
                        j++;
                    }
                    else
                    {
                        str[i][j] = '\0';
                        break;
                    }
                }
                cin>> n[i];
                getchar();
                indx[i] = i;
            }
            cout<< "Case #"<< tc<< ":"<< endl;

            for(int i=1; i<10; i++)
            {
                for(int j=i; j>0; j--)
                {
                    if(n[j]>n[j-1])
                    {
                        swap(n[j], n[j-1]);
                        swap(indx[j], indx[j-1]);
                    }
                }
            }

            int x = n[0];
            for(int i=0; i<10; i++)
            {
                if(n[i]==x)
                {
                    cout<<str[indx[i]]<< endl;
                }
                else
                    break;
            }

        }
    }
    return 0;
}
