#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, p, q, i, j;
    while(cin>> t)
    {
        for(j=1; j<=t; j++)
        {
            cin>> n>> p>> q;
            int wt[35];
            for(i=0; i<n; i++)
                cin>> wt[i];
            sort(wt, wt+n);
            int twt{0};
            int x{0};
            for(i=0; i<n; i++)
            {
                twt += wt[i];
                if(twt>q)
                {
                    break;
                }
                x++;
                if(x == p)
                    break;
            }
            cout<< "Case "<< j<< ": "<< x<< endl;
        }
    }
    return 0;
}