#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int h1, h2, m1, m2, ans;
    while(1)
    {
        cin>> h1>> m1>> h2>> m2;
        if(h1==0 && m1==0 && h2==0 && m2==0)
            break;

        if(h2<h1 || (h2==h1 && m2<m1))
            h2+=24;

        ans =  ((h2-h1)*60)+(m2-m1);

        cout << ans << endl;
    }
    return 0;
}

