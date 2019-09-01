#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    while(cin>> n)
    {
        t = n;
        while(n>1)
        {
            t += n/3;
            n = n/3 + n%3;
            if(n==2)
                n = 3;
        }
        cout<< t<< endl;
    }
    return 0;
}
