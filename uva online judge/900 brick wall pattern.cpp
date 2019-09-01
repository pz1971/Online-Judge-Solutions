#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long ar[52];
    int i, n;
    ar[0]=1;
    ar[1]=1;
    for(i=2; i<52; i++)
    {
        ar[i] = ar[i-1]+ ar[i-2];
    }
    while(1)
    {
        cin>> n;
        if(n==0)
            break;
        else
            cout<< ar[n]<< endl;
    }
    return 0;
}
