#include <bits/stdc++.h>
using namespace std;
 
int main()
{

    int t, c, k, w;
    cin>> t;
    while(t--)
    {
        cin>> c>> k>> w;
        if(k<c*w)   cout<< "no"<< endl;
        else        cout<< "yes"<< endl;
    }
 
    return 0;
} 