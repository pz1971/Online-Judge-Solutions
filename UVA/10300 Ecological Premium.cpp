#include<bits/stdc++.h>
using namespace std;
int main()
{
    size_t t;
    while(cin>> t)
    {
        while(t--)
        {
            int sum{}, f{};
            cin>> f;
            while(f--)
            {
                int x, y, z;
                cin>> x>> y>> z;
                sum += x*z;
            }
            cout<< sum<< endl;
        }
    }
    return 0;
}
