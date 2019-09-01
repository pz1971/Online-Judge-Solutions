#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t, i, j, ar[13], n;
    ar[0]=0;
    cin>> t;
    for(i=1; i<=t; i++)
    {
        cin>> n;
        for(j=1; j<=n; j++)
            cin>> ar[j];
        cout<< "Case "<< i<< ": ";
        cout<< ar[(n+1)/2] <<endl;
    }
    return 0;
}

