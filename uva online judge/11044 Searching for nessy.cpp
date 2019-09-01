#include<bits/stdc++.h>
using namespace std;
int main()
{
    size_t n;
    while(cin>> n)
    {
        while(n--)
        {
            int n, m;
            cin>> n>> m;
            n -=2;
            m-= 2;
            long int x{}, y{};
            x = n/3;
            if(x*3 != n)
                x++;
            y = m/3;
            if(y*3 != m)
                y++;
            cout<< x*y<< endl;
        }
    }
    return 0;
}
