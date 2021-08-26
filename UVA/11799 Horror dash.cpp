#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        for(int tc=1; tc<=t; tc++)
        {
            int m{}, x;
            cin>> m;
            while(1)
            {
                cin>> x;
                if(x>m)
                    m = x;
                char ch = getchar();
                if(ch=='\n')
                    break;
            }
            cout<< "Case "<< tc<< ": "<< m<< endl;
        }
    }
    return 0;
}
