#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        for(int tc=1; tc<=t; tc++)
        {
            int n, h{}, l{}, x{};
            cin>> n;
            cin>> x;
            while(--n)
            {
                int y;
                cin>> y;
                if(y>x)
                    h++;
                else if(y<x)
                    l++;
                x = y;
            }
            cout<< "Case "<< tc<< ": "<< h<< " "<< l<< endl;
        }
    }
    return 0;
}
