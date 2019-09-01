#include<bits/stdc++.h>
using namespace std;
int main()
{
    size_t t;
    while(cin>> t)
    {
        while(t--)
        {
            int n{}, a{-1}, b{1000};
            cin>> n;
            while(n--)
            {
                int x;
                cin>> x;
                if(a < x)
                    a = x;
                if(b > x)
                    b = x;
            }
            cout<< (a-b)*2<< endl;
        }
    }
    return 0;
}
