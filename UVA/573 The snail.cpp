#include<bits/stdc++.h>
using namespace std;
int main()
{
    double h, u, d, f;
    while(cin>> h>> u>> d>> f && h!=0)
    {
        double r{}, h2{};
        int day{};
        r = u * f / 100.0;
        while(++day)
        {
            h2 += u;
            if(h2>h)
            {
                cout<< "success on day "<< day << endl;
                break;
            }
            h2 -= d;
            if(h2<0)
            {
                cout<< "failure on day "<< day << endl;
                break;
            }
            u -= r;
            if(u<0)
                u = 0;
        }
    }
    return 0;
}
