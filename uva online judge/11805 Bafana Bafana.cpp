#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k, p;

    while(cin>>t)
    {
        for(int i=1; i<=t; i++)
        {
            cin>> n>> k>> p;
            int ans = (k+p)%n;
            if(ans == 0)
                ans = n;
            cout<< "Case "<< i<< ": "<< ans<< endl;
        }
    }
    return 0;
}
