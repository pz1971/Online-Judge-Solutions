#include<bits/stdc++.h>
using namespace std;
long long digiop(long long x)
{
    long long sum = 0;
    while(x)
    {
        sum += (x%10) * (x%10);
        x /= 10;
    }
    return sum;
}
int main()
{
    long long int n, x;
    int t, i;
    while(cin>>t)
    {
        for(i=1; i<=t; i++)
        {
            cin>> x;
            n = x;
            while(n/10!=0)
            {
                n = digiop(n);
            }
            if(n==1 || n==7)
                printf("Case #%d: %lld is a Happy number.\n", i, x);
            else
                printf("Case #%d: %lld is an Unhappy number.\n", i, x);
        }
    }
    return 0;
}
