#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>> n)
    {
        while(n--)
        {
            double x, y, r;
            cin>> x>> y>> r;
            x = sqrt(x*x + y*y);
            y = r + x;
            x = r - x;
            cout<< fixed<< showpoint<< setprecision(2);
            cout<< x<< " "<< y<< endl;
        }
    }
    return 0;
}
