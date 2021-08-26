#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    while(cin>> n && n)
    {
        long long x = sqrt(n);
        x*x==n ? cout<< "yes" : cout<< "no";
        cout<< endl;
    }
    return 0;
}
